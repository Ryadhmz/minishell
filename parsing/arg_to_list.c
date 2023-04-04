/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:03:16 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 03:54:29 by rhamza           ###   ########.fr       */
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
        if((*s)[i] == quote)
        {
            i++;
            break;
        }
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

t_db_list *arg_to_list(char *arg)
{
    t_db_list *list_arg;
    t_db_list *last;

    list_arg = NULL;
    while(1)
    {
        ft_dblstadd_back(&list_arg, insert_arg(&arg));
        last = ft_dblstlast(list_arg);
        if(ft_strlen(last->data) == 0)
        {
            ft_pop(&list_arg);
            break;
        }
    }
    return(list_arg);
}
