/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:03:16 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 01:55:51 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int count_carac_arg(char **s) // si pas d'espaces apres ou avant quotes : reste le mm argument, les premiers esp
{ 
    char quote;
    int i;
    int if_quote;

    i = 0;
    if_quote = 0;
    while((*s)[0] == ' ' && (*s)[0] != '\0')
        (*s)++;
    while((*s)[i] != ' ' && (*s)[i] != '\0')
    {
        if((*s)[i] == 39 || (*s)[i] == 34)
        {
            quote = (*s)[i++];
            if_quote = 1;
            break;
        }
        i++;
    }
    while(if_quote == 1 && (*s)[i] != '\0')
    {
        if((*s)[i++] == quote)
            break;
        i++;
    }
    return(i);
}

static char *insert_arg(char **s)
{
    int size_arg;
    char *arg;
    int i;
    
    size_arg = count_carac_arg(s);
    i = 0;
    arg = NULL;
    arg = malloc(sizeof(char) * (size_arg + 1));
    if(!arg)
        return(NULL);
    while(i < size_arg)
    {
        arg[i] = (*s)[0];
        i++;
        (*s)++;
    }
    arg[i] = '\0';
    return(arg);
}

t_db_list arg_to_list(char *arg)
{
    t_db_list *list_arg;

    list_arg = NULL;
    ft_dblstadd_back(&list_arg, insert_arg(&arg));
}

// int main(void)
// {
//     char *str = "arg1 \'arg2 with spaces\' arg3";
//     // printf("%d\n", count_carac_arg(&str));
//     printf("%s\n", insert_arg(&str));
//     printf("%s\n", insert_arg(&str));
//     return 0;
// }