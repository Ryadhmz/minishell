/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:54 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 17:28:31 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int last_arg_pipe(t_db_list *list_arg)
{
    t_db_list *last_node;
    char *str;
    
    last_node = ft_dblstlast(list_arg);
    str = last_node->data;

    if(str[0] == '|')
        return(-1);
    return (0);
}

int check_nb_pipe(char *str)
{
    int i;
    int nb_pipe;

    i = 0;
    nb_pipe = 0;

    while(str[i])
    {
        if(str[i] != '|')
            break;
        i++;
        nb_pipe++;
    }
    if(nb_pipe > 2)
        return(-1);
    return (0);
}

int check_pipe(t_db_list *list_arg)
{
    char *str;
    while(list_arg)
    {
        str = list_arg->data;
        if(check_nb_pipe(str) == -1)
            return (-1);
        list_arg = list_arg->next;
    }
    return (0);
}

int check_nb_and(char *str)
{
    int i;
    int nb_and;

    i = 0;
    nb_and = 0;

    while(str[i])
    {
        if(str[i] != '&')
            break;
        i++;
        nb_and++;
    }
    if(nb_and > 2)
        return(-1);
    return (0);
}

int check_and(t_db_list *list_arg)
{
    char *str;
    while(list_arg)
    {
        str = list_arg->data;
        if(check_nb_and(str) == -1)
            return (-1);
        list_arg = list_arg->next;
    }
    return (0);
}