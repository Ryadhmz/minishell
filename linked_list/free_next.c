/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:39:21 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 06:52:48 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void free_next(t_db_list **lst)
{
    t_db_list *current;

    if((*lst) == NULL)
        return ;
    current = (*lst);
    if((*lst)->next != NULL)
    {
        (*lst) = (*lst)->next;
        free(current);
        current = NULL;
    }
}