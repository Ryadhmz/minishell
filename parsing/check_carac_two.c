/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carac_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:54:53 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 17:28:30 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int last_arg_and(t_db_list *list_arg)
{
    t_db_list *last_node;
    char *str;
    
    last_node = ft_dblstlast(list_arg);
    str = last_node->data;

    if(str[0] == '&')
        return(-1);
    return (0);
}