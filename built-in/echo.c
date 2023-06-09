/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:12:51 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/11 23:33:14 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int print_echo(t_db_list *list)
{
    while(list != NULL)
    {
        printf("%s", list->data);
        if(list->next != NULL)
        {
            printf(" ");
            list = list->next;
        }
        else
            break;
    }
    return (0);
}

int ft_echo(t_db_list **list_arg)
{
    int if_bn;

    if_bn = 0;
    if(list_arg == NULL)
        return(-1);
    free_next(list_arg);
    while((*list_arg)->data[0] == '-')
    {
        if(while_carac(((*list_arg)->data), 'n') == 0)
        {
            if_bn = 1;
            free_next(list_arg);
            if((*list_arg)->next == NULL)
                break;
        }
        else
            break;
    }
    print_echo(*list_arg);
    if(if_bn == 0)
        printf("\n");
    return (0);
}