/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:00:39 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 18:05:26 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_db_list	*ft_dblstnew(char *data)
{
	t_db_list	*cell;

	cell = malloc(sizeof(t_db_list));
	if (!cell)
		exit(1);
	cell->data = data;
	cell->next = NULL;
	cell->past = NULL;
	return (cell);
}