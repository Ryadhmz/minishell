/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_carac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:00:20 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 01:07:37 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int while_carac(char *str, char c)
{
    int i;

    i = 1;
    if(ft_strlen(str) == 0)
        return(-1);
    while(str[i])
    {
        if(str[i] == '\0')
            break;
        if(str[i] != c)
            return(-1);
        i++;
    }
    return(0);
}