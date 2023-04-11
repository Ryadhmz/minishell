/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:18:40 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 01:44:56 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ctrl_backslash(void)
{
}

void ft_signal(void)
{
    signal(SIGQUIT, (void *)ctrl_backslash);
    rl_catch_signals = 0;
    // signal()
    // ctrl_backslash_c(void);
    // ctrl_backslash_d(void);
}