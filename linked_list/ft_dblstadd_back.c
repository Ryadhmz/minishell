/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:02:27 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 18:05:47 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_dblstadd_back(t_db_list **db_lst, char *data)
{
	t_db_list	*cur;
	t_db_list	*save_new;

	if (*db_lst == NULL)
		*db_lst = ft_dblstnew(data);
	else
	{
		cur = ft_dblstlast(*db_lst);
		cur->next = ft_dblstnew(data);
		save_new = cur->next;
		save_new->past = cur;
	}
}