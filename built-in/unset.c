/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:43:22 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 09:15:41 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int search_env_var(char *str)
{
    t_db_list *lst_env;

    lst_env = g_ms->env;
    while(lst_env->next != NULL)
    {
        if(ft_strcmp(str, lst_env->data) == 0)
            return(0)
        lst_env = lst_env->next; 
    }
    lst_env = ft_db_first_node(lst_env);
    return(1);
}

int ft_unset(t_db_list **list_arg)
{
    free_next(list_arg);
    if((*list_arg) == NULL)
        return(0);
    while(1)
    {
        if(search_env_var((*list_arg)->data) == 0)
            remove_var((*list_arg)->data);
        if((*list_arg)->next == NULL)
        {
            free_next(list_arg);
            break;
        }
        else
            free_next(list_arg);
    }
    return(0);
}