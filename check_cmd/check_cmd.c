/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:56:49 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 16:53:12 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_cmd(t_list **list_arg)
{
    if((*list_arg) == NULL)
        return(1);
    if(ft_strcmp("echo", (*list_arg)->data) == 0)
        // echo
    else if(ft_strcmp("cd", (*list_arg)->data) == 0)
        // fonction
    else if(ft_strcmp("pwd", (*list_arg)->data) == 0)
        // pwd
    else if(ft_strcmp("unset", (*list_arg)->data) == 0)
        // env
    else if(ft_strcmp("exit", (*list_arg)->data) == 0)
        // exit
    else if(ft_strcmp("env", (*list_arg)->data) == 0)
        ft_env(list_arg);
    else
        // execve
}