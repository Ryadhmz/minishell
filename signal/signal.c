/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:18:40 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 02:39:44 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ctrl_sigint(void)
{
    printf("\n");
    // ft_prompt(g_ms.fd);

    //PENSER A RL ON NEW LINE
}

void ctrl_backslash(void)
{
}

void ft_signal(void)
{
    rl_catch_signals = 0;
    signal(SIGQUIT, (void *)ctrl_backslash);
    signal(SIGINT, (void *)ctrl_sigint);
    // ctrl_backslash_c(void);
    // ctrl_backslash_d(void);
}