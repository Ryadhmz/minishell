/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:20:06 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 07:23:50 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_list(t_db_list *lst)
{
    printf("Print list : \n");
    while(lst != NULL)
    {
        printf("%s", lst->data);
        if(lst->next != NULL)
        {
            printf("-->");
        }
        lst = lst->next;
    }
    printf("\n");
}