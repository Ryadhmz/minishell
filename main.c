/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:54:15 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 17:58:25 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void set_arg_struct(char **env)
{
    g_ms.env = env;
    g_ms.split_path = search_path("PATH", g_ms);
}

int main(int argc, char **argv, char **env)
{
    set_arg_struct(env);
    return (0);
}