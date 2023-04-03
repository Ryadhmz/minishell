/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:19:13 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/03 18:29:51 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si le nb de guillements et bon puis mettre tt les arguments dans une liste chainee arg

static int ft_quotes(char *str, int simple_quote, int double_quote) // si impair quotes pas bon sauf si dans autres types de quotes 
{
    int if_quote;
    
    if_quote = 0;
    while(str[0] != '\0')
    {
        if(str[0] == 39 && simple_quote < 2 && double_quote == 0) // simple quote
            simple_quote += 1;
        else if(str[0] == 34 && double_quote < 2 && simple_quote == 0) // double quote
            double_quote += 1;
        if(simple_quote == 2)
        {
            if_quote = 1;
            simple_quote = 0;
        }
        if(double_quote == 2)
        {
            if_quote = 1;
            double_quote = 0;
        }
        str += 1;
    }
    if((simple_quote % 2 == 0 || simple_quote == 0) && (double_quote % 2 == 0 || double_quote == 0))
        return (0);
    return (-1);
}
#include <stdio.h>
void parsing(char *str)
{
    printf("%d\n", ft_quotes(str, 0, 0));
    // parsed = ft_split_boost(str);
}