/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:38 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/03 17:40:21 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct db_linked_list
{
	char					*data;
	struct db_linked_list	*next;
	struct db_linked_list	*past;
}							t_db_list;

typedef struct mini_struct
{
    t_db_list *env;
    char **split_path;
}   t_mini_struct;

t_mini_struct g_ms;

// utils

char	**ft_split(char const *s, char c);
char	**ft_split_boost(char *s);
void	freebox(char **db_tab);
char **search_path(char *search, char **env);
int ft_strlen(const char *str);

// built-in

void pwd(void);
void ft_env(void);
t_db_list *list_env(char **env);

// linked_list

t_db_list	*ft_dblstnew(char *data);
t_db_list	*ft_dblstlast(t_db_list *db_lst);
void	ft_dblstadd_back(t_db_list **db_lst, char *data);
t_db_list	*ft_db_first_node(t_db_list *node_lambda);

// parsing

void parsing(char *str);

#endif