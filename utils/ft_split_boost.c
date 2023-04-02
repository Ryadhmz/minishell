/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_boost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:23:37 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/03 01:00:09 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int count_carac_word(char **s)
{
    int i;

    i = 0;
    while(((*s)[0] == ' ' || (*s)[0] == '\t' || (*s)[0] == '\n') && (*s)[0] != '\0')
        (*s)++;
    while((*s)[i] != ' ' && (*s)[i] != '\t' && (*s)[i] != '\n' && (*s)[i] != '\0')
    {
        i++;
    }
    return(i);
}

static char *insert_word(char **s)
{
    char *word;
    int i;

    i = 0;
    word = malloc(sizeof(char) * count_carac_word(s));
    if(!word)
        return(NULL);
    while(((*s)[0] == ' ' || (*s)[0] == '\t' || (*s)[0] == '\n') && (*s)[0] != '\0')
        (*s)++;
    while((*s)[0] != ' ' && (*s)[0] != '\t' && (*s)[0] != '\n' && (*s)[0] != '\0')
    {
        word[i] = (*s)[0];
        i++;
        (*s)++;
    }
    word[i] = '\0';
    return(word);
}

static int	countword(char const *s)
{
	int	i;
	int	nb_word;
	int	reload;

	i = 0;
	nb_word = 0;
	reload = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && reload == 0)
		{
			nb_word++;
			reload = 1;
		}
		else if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			reload = 0;
		i++;
	}
	return (nb_word);
}

char	**ft_split_boost(char *s)
{
    int count_word;
    int i;
    char **db_tab;

    count_word = countword(s);
    i = 0;
    db_tab = malloc(sizeof(char *) * count_word + 1);
    if(!db_tab)
        return(NULL);
    while(i < count_word)
    {
        db_tab[i] = insert_word(&s);
        if (!db_tab[i])
		{
			freebox(db_tab);
			return (NULL);
		}
        i++;
    }
    db_tab[i] = NULL;
    return (db_tab);
}