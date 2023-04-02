/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_first_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:52:17 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 19:00:48 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_db_list	*ft_db_first_node(t_db_list *node_lambda)
{
	t_db_list	*cur;

	cur = node_lambda;
	if (cur == NULL)
		return (NULL);
	if (cur->past != NULL)
	{
		while (cur->past != NULL)
			cur = cur->past;
	}
	return (cur);
}