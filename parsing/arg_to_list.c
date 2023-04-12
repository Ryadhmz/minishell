/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:03:16 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 17:28:27 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void trim_if_quotes(t_db_list **list_arg)
{
    int i;

    i = 0;
    while((*list_arg) != NULL)
    {
        while(((*list_arg)->data[i] != '\"' && (*list_arg)->data[i] != '\'' && (*list_arg)->data[i]))
            i++;
        if((*list_arg)->data[i] == '\'')
            (*list_arg)->data = remove_carac((*list_arg)->data, '\'');
        else if((*list_arg)->data[i] == '\"')
            (*list_arg)->data = remove_carac((*list_arg)->data, '\"');
        if((*list_arg)->next != NULL)
        {
            i = 0;
            (*list_arg) = (*list_arg)->next;
        }
        else
            break;
    }
    if((*list_arg) != NULL)
        (*list_arg) = ft_db_first_node((*list_arg));
}

static int count_carac_arg_t(char **s, int if_quote, int i, char quote)
{
    while((*s)[i] != ' ' && (*s)[i] != '\0')
        i++;
    return(i);
}

static int count_carac_arg(char **s, int if_quote, int i, char quote) // si pas d'espaces apres ou avant quotes : reste le mm argument, les premiers esp
{   
    while((*s)[0] == ' ' && (*s)[0] != '\0')
        (*s)++;
    while((*s)[i] != ' ' && (*s)[i] != '\0')
    {
        if((*s)[i] == 39 || (*s)[i] == 34)
        {
            quote = (*s)[i++];
            if_quote = 1;
            break;
        }
        i++;
    }
    while(if_quote == 1 && (*s)[i] != '\0')
    {
        if((*s)[i] == quote)
        {
            i++;
            if_quote = 2;
            break;
        }
        i++;
    }
    return(count_carac_arg_t(s, if_quote, i, quote));
}

static char *insert_arg(char **s)
{
    int size_arg;
    char *arg;
    int i;
    
    size_arg = count_carac_arg(s, 0, 0, 0);
    i = 0;
    arg = NULL;
    arg = malloc(sizeof(char) * (size_arg + 1));
    if(!arg)
        return(NULL);
    while(i < size_arg)
    {
        arg[i] = (*s)[0];
        i++;
        (*s)++;
    }
    arg[i] = '\0';
    return(arg);
}

t_db_list *arg_to_list(char *arg)
{
    t_db_list *list_arg;
    t_db_list *last;

    list_arg = NULL;
    while(1)
    {
        ft_dblstadd_back(&list_arg, insert_arg(&arg));
        last = ft_dblstlast(list_arg);
        if(ft_strlen(last->data) == 0)
        {
            ft_pop(&list_arg);
            break;
        }
    }
    // trim_if_quotes(&list_arg);
    list_arg = ft_db_first_node(list_arg);
    return(list_arg);
}