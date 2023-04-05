/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:17:22 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 07:15:59 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pop(t_db_list **head)
{
	t_db_list *current;
	t_db_list *previous;
	
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) 
	{
        free((*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    current = *head;
    previous = NULL;
    while (current->next != NULL) 
	{
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current->data);
    free(current);
	current = NULL;
}