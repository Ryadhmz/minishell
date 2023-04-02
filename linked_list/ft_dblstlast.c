/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:02:11 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 18:20:50 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_db_list	*ft_dblstlast(t_db_list *db_lst)
{
	if (!db_lst)
		return (NULL);
	while (db_lst->next != NULL)
		db_lst = db_lst->next;
	return (db_lst);
}