/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:19:13 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/11 17:55:38 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int last_arg_pipe(t_db_list *list_arg)
{
    t_db_list *last_node;
    char *str;
    
    last_node = ft_dblstlast(list_arg);
    str = last_node->data;

    if(str[0] == '|')
        return(-1);
    return (0);
}

int check_nb_pipe(char *str)
{
    int i;
    int nb_pipe;

    i = 0;
    nb_pipe = 0;

    while(str[i])
    {
        if(str[i] != '|')
            break;
        i++;
        nb_pipe++;
    }
    if(nb_pipe > 2)
        return(-1);
    return (0);
}

int check_pipe(t_db_list *list_arg)
{
    char *str;
    while(list_arg)
    {
        str = list_arg->data;
        if(check_nb_pipe(str) == -1)
            return (-1);
        list_arg = list_arg->next;
    }
    return (0);
}

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
    {
        printf("unclosed paranthesis\n");
        return(-1);
    }
    list_arg = arg_to_list(str);
    if(check_pipe(list_arg) == -1 || last_arg_pipe(list_arg) == -1)
    {
        printf("Erreur pipe\n"); 
        return(-1);
    }
    print_list(list_arg);
    // check_cmd(&list_arg); doit être géré après les pipes
    return (0);
}