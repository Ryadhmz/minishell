/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:17:01 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 04:17:36 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isascii(int ascii)
{
	if (ascii >= 0 && ascii <= 127)
	{
		return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (!ft_isascii(s1[i]) || !ft_isascii(s2[i]))
			i++;
		if ((s1[i] > s2[i]) || !s2[i])
			return (1);
		if ((s1[i] < s2[i]) || !s1[i])
			return (-1);
		i++;
	}
	return (0);
}

// utile pour chercher les built-in, le split est utile pour chercher dans chaque truc petit a petit
char **search_path(char *search, t_mini_struct glo_shell)
{
    int i;
    int j;
    int size_search;
	char **env;

    i = 0;
    j = 0;
    size_search = ft_strlen(search);
	env = glo_shell.env;
    while(env[j][i])
    {
        if(ft_strncmp(env[j], search, size_search) != 0)
            j++;
        else
            break;
    }
    return(ft_split(glo_shell.env[j], ':'));
}