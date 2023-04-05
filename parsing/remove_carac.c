/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_carac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:16:39 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 02:35:16 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *new_str_without_carac(char *str, char *new_str, char c)
{
    int i;
    int i_two;

    i = 0;
    i_two = 0;
    while(str[i])
    {
        if(str[i] != c)
        {
            new_str[i_two] = str[i];
            i_two += 1;
        }
        i += 1;
    }
    new_str[i] = '\0';
    return(new_str);
}

char *remove_carac(char *str, char c)
{
    int i;
    int good_carac;
    char *new_str;
    
    i = 0;
    good_carac = 0;
    
    if(str == NULL)
        return(NULL);
    while(str[i])
    {
        if(str[i] != c)
            good_carac += 1;
        i++;
    }
    new_str = malloc(sizeof(char) * (good_carac + 1));
    if(!new_str)
        return(NULL);
    i = 0;
    return(new_str_without_carac(str, c, ))
}