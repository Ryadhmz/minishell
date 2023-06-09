/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:38 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/23 09:56:01 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1000)
# endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
// #include "globals.c"

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
	int fd;
}   t_mini_struct;

// t_mini_struct g_ms;

// utils

char	**ft_split(char const *s, char c);
char	**ft_split_boost(char *s);
void	freebox(char **db_tab);
char **search_path(char *search, char **env);
int ft_strlen(const char *str);
int ft_strcmp(const char *s1, const char *s2);
int while_carac(char *str, char c);
int check_last_carac(char *str, char c);

// built-in

void pwd(void);
int ft_env(t_db_list **list_arg, t_mini_struct *g_ms);
t_db_list *list_env(char **env);
int ft_echo(t_db_list **list_arg);

// linked_list

t_db_list	*ft_dblstnew(char *data);
t_db_list	*ft_dblstlast(t_db_list *db_lst);
void	ft_dblstadd_back(t_db_list **db_lst, char *data);
t_db_list	*ft_db_first_node(t_db_list *node_lambda);
void	ft_pop(t_db_list **head);
void print_list(t_db_list *lst);
void free_next(t_db_list **lst);
void	free_list(t_db_list **head);

// parsing

int parsing(char *str);
t_db_list *arg_to_list(char *arg);
char	*ft_strtrim(char const *s1, char const *set);
char *remove_carac(char *str, char c);
int last_arg_and(t_db_list *list_arg);
int check_and(t_db_list *list_arg);
int check_nb_and(char *str);
int check_pipe(t_db_list *list_arg);
int check_nb_pipe(char *str);
int last_arg_pipe(t_db_list *list_arg);

// run cmd

int check_cmd(t_db_list **list_arg, t_mini_struct *g_ms);


// signal

void ft_signal(void);

// prompt

void ft_prompt(int fd);

// gnl

char	*get_next_line(int fd);
char	*return_line(char *stash);
int		check_of_line(char *stash);
char	*return_without_stock(int fd, char *stash);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*clean_stash(char *stash);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*free_return(char **str);

#endif