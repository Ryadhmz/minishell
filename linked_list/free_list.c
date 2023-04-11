/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:46:01 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/11 23:47:51 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_list(t_db_list **head)
{
	t_db_list *current;
	t_db_list *next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		if(current != NULL)
			current->past = NULL;
	}
}