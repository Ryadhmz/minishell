/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:15 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 04:19:23 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_struct glo_shell;

void set_arg_struct(char **env)
{
    glo_shell.env = env;
    glo_shell.split_path = search_path("PATH", glo_shell);
}

int main(int argc, char **argv, char **env)
{
    set_arg_struct(env);
    printf("Path : %s\n", glo_shell.split_path[0]);
    return (0);
}