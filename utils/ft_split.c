/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:23:30 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/04 01:01:33 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	freebox(char **db_tab)
{
	int	i;

	i = 0;
	while (db_tab[i])
	{
		free(db_tab[i]);
		i++;
	}
	free(db_tab);
}

static int	countword(char const *s, char c)
{
	int	i;
	int	nb_word;
	int	reload;

	i = 0;
	nb_word = 0;
	reload = 0;
	while (s[i])
	{
		if (s[i] != c && reload == 0)
		{
			nb_word++;
			reload = 1;
		}
		else if (s[i] == c)
			reload = 0;
		i++;
	}
	return (nb_word);
}

static char	*insert_word(char const *s, char c, int i, int j)
{
	char	*word;

	i = 0;
	while ((s[i]) == c && ft_strlen(s) > i)
		i++;
	while (s[i] != c && ft_strlen(s) > i)
	{
		i++;
		j++;
	}
	word = malloc(j + 1 * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && ft_strlen(s) > i)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_extand(char const *s, char **db_tab, char c,
		int countwordd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (countwordd--)
	{
		db_tab[i] = insert_word(s, c, i, j);
		if (!db_tab[i])
		{
			freebox(db_tab);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && ft_strlen(s) > j)
			j++;
		while (j--)
			s = s + 1;
		i++;
		j = 0;
	}
	db_tab[i] = NULL;
	return (db_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**db_tab;
	int		countwordd;

	countwordd = countword(s, c);
	if (!s)
		return (NULL);
	db_tab = malloc((countwordd + 1) * sizeof(char *));
	if (!db_tab)
		return (NULL);
	return (ft_split_extand(s, db_tab, c, countwordd));
}