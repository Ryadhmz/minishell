/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:17:01 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 03:41:23 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// utile pour chercher les built-in, le split est utile pour chercher dans chaque truc petit a petit
char *search_path(char *search)
{
    int i;
    int j;
    int size_search;

    i = 0;
    j = 0;
    size_search = ft_strlen(search);
    while(env[j][i])
    {
        if(i == size_search - 1)
            return(ft_split(env[j], ':'));
        
    }
}