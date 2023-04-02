/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:19:13 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/03 01:37:19 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si le nb de guillements et bon puis mettre tt les arguments dans une liste chainee arg

int ft_quotes(char **parsed, char *str) // si impair quotes pas bon sauf si dans autres types de quotes 
{
    
}

void parsing(char *str)
{
    char **parsed;
    
    parsed = ft_split_boost(str);
    
}