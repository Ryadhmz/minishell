/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:38 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 18:05:44 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct mini_struct
{
    char **env;
    char **split_path;
}   t_mini_struct;

typedef struct db_linked_list
{
	char					*data;
	struct db_linked_list	*next;
	struct db_linked_list	*past;
}							t_db_list;

t_mini_struct g_ms;

char	**ft_split(char const *s, char c);
char **search_path(char *search, t_mini_struct glo_shell);
int ft_strlen(const char *str);
void pwd(void);



#endif