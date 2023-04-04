/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:12:51 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 19:21:17 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_echo(t_db_list **list_arg) // echo -> check si -n -> tant que -n continue, print tout ce qu'il y a après
{
    int if_bn;

    if_bn = 0;
    free_next(list_arg);
    if(list_arg == NULL)
        return(-1);
    while((*list_arg)->data[0] == '-')
    {
        if(while_carac(((*list_arg)->data[0]), 'n') == 0)
        {
            if_bn = 1;
            free_next(list_arg);
            if((*list_arg) == NULL)
                break;
        }
        else
            break;
    }
    print_list(list_arg);
    if(if_bn == 1)
        printf("\n");
}