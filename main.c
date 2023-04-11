/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:15 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/11 15:28:32 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_prompt(void)
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
    if(parsing(input) == -1) // parser puis faire qqch avec la commande
        break;
    add_history(input);
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
    set_arg_struct(env);
    ft_prompt();
    return (0);
}