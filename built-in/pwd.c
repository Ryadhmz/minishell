/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:41:29 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/05 00:09:43 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void pwd(void)
{
    char *pwd;

    pwd = NULL;
    pwd = getcwd(pwd, 0);
    printf("%s\n", pwd);
    free(pwd);
}