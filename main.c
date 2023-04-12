/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:15 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 19:02:06 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void reload_history(int fd)
{
    char *str_ret;

    str_ret = NULL;
    while((str_ret = get_next_line(fd)) != NULL)
    {
        str_ret = remove_carac(str_ret, '\n');
        add_history(str_ret);
    }
}

void add_my_history(char *input, int fd)
{
    add_history(input);
    write(fd, input, ft_strlen(input));
    write(fd, "\n", 1);
}

void ft_prompt(int fd)
{
    char *input;

    while(1)
    {
        input = readline("minishell-1.0$ ");
        if(!input) // arrive quand l'user utile ctrl + D
        {
            printf("\n");
            break;
        }
        add_my_history(input, fd);
        if(parsing(input) == -1) // parser puis faire qqch avec la commande
        {
            free(input);
            ft_prompt(fd);
        }
        free(input);
    }
}

static void set_arg_struct(char **env)
{
    g_ms.env = list_env(env);
    g_ms.split_path = search_path("PATH", env);
}

int main(int argc, char **argv, char **env)
{
    int fd;
    
    set_arg_struct(env);
    fd = open(".history.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    reload_history(fd);
    ft_signal();
    ft_prompt(fd);
    return (0);
}