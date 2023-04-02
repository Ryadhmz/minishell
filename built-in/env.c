/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:52:46 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 19:00:48 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_db_list *list_env(char **env)
{
    t_db_list *list_env;
    int i;

    list_env = NULL;
    i = 0;
    while(env[i] != NULL)
    {
        ft_dblstadd_back(&list_env, env[i]);
        i++;
    }
    return(list_env);
}

void ft_env(void) // gerer plusieurs env enchainé
{
    t_db_list *env_cpy;

    env_cpy = g_ms.env;
    env_cpy = ft_db_first_node(env_cpy);
    while(env_cpy != NULL)
    {
        printf("%s\n", env_cpy->data);
        env_cpy = env_cpy->next;
    }
}