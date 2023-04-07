/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:00:31 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/06 00:09:57 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    if(ft_strlen(s1) != ft_strlen(s2))
        return(-1);
    while(s1[i])
    {
        if(s1[i] != s2[i])
            return(-1);
        i++;
    }
    return(0);
}