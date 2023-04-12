/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:18:40 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/12 18:40:00 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ctrl_sigint(void)
{
    write(1, "\n", 1);
    rl_on_new_line(); // indique que l'user a appuye sur entree
    rl_replace_line("", 0); 
    rl_redisplay();
    //PENSER A RL ON NEW LINE
}

// void ctrl_d(void)
// {
//     free tout puis quitter, si je relance minishell j'aurais tjr l'historique grace au .history
// }

void ctrl_backslash(void)
{
}



void ft_signal(void)
{
    rl_catch_signals = 0;
    signal(SIGQUIT, (void *)ctrl_backslash);
    signal(SIGINT, (void *)ctrl_sigint);
    // signal(EOF, (void *)ctrl_d);
}