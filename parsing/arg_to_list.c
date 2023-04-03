/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:03:16 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 01:38:19 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int count_carac_arg(char **s) // si pas d'espaces apres ou avant quotes : reste le mm argument, les premiers esp
{ 
    char quote;
    int i;
    int if_quote;

    i = 0;
    if_quote = 0;
    while((*s)[0] == ' ' && (*s)[0] != '\0')
        (*s)++;
    while((*s)[i] != ' ' && (*s)[i] != '\0')
    {
        if((*s)[i] == '\'' || (*s)[i] == '\"')
        {
            quote = (*s)[i++];
            if_quote = 1;
            break;
        }
        i++;
    }
    while(if_quote == 1 && (*s)[i] != '\0')
    {
        if((*s)[i++] == quote)
            break;
        i++;
    }
    return(i);
}

// t_db_list arg_to_list(char *arg)
// {
//     t_db_list list_arg;

//     list_arg = NULL;
// }

int main(void)
{
    return 0;
}