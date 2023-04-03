/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:19:13 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 01:06:56 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si le nb de guillements et bon puis mettre tt les arguments dans une liste chainee arg

static int ft_quotes(char *str, int simple_quote, int double_quote)
{
    int if_quote;
    
    if_quote = 0;
    while(str[0] != '\0')
    {
        if(str[0] == 39 && simple_quote < 2 && double_quote == 0)
            simple_quote += 1;
        else if(str[0] == 34 && double_quote < 2 && simple_quote == 0)
            double_quote += 1;
        if(simple_quote == 2 || double_quote == 2)
        {
            if_quote = 1;
            simple_quote = 0;
            double_quote = 0;
        }
        str += 1;
    }
    if((simple_quote % 2 == 0 || simple_quote == 0) && (double_quote % 2 == 0 || double_quote == 0))
        return (if_quote);
    return (-1);
}

int parsing(char *str)
{
    int if_quote;
    char **parsed;
    t_db_list *list_arg;
    
    if_quote = ft_quotes(str, 0, 0);
    if(if_quote == -1)
        return(-1);
    parsed = ft_split(str, ' ');
    list_arg = arg_to_list(parsed);
    return (0);
}