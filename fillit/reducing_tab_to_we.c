/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducing_tab_to_we.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:26:18 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 11:14:17 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		hdts(char *s)
{
	while (*s)
	{
		if (*s != '.')
			return (0);
		s++;
	}
	return (1);
}

static int		vdts(char **tab, int i, int tab_count)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < tab_count)
	{
		if (tab[j][i] == '.')
			count++;
		j++;
	}
	if (count == tab_count)
		return (1);
	return (0);
}

static char		**reducing_tab_part2(char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (ct_tabs(tab)))))
		return (0);
	while (i < ct_tabs(tab) - 1)
	{
		if (hdts(tab[0]) == 1)
			new_tab[i] = ft_strdup(tab[i + 1]);
		else
			new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

static char		**reducing_tab_part3(char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (ct_tabs(tab) + 1))))
		return (0);
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

char			**reducing_tab_to_we(char **tab)
{
	int		i;
	char	**new_tab;

	new_tab = NULL;
	i = 0;
	if (hdts(tab[0]) == 1 || hdts(tab[ct_tabs(tab) - 1]) == 1)
		new_tab = reducing_tab_part2(tab);
	else if (vdts(tab, 0, ct_tabs(tab)) == 1 || vdts(tab, 3, ct_tabs(tab)) == 1)
	{
		if (!(new_tab = (char **)malloc(sizeof(char *) * (ct_tabs(tab) + 1))))
			return (0);
		while (i < ct_tabs(tab))
		{
			if (vdts(tab, 0, ct_tabs(tab)) == 1)
				new_tab[i] = ft_strsub(tab[i], 1, ft_strlen(tab[i]) - 1);
			else
				new_tab[i] = ft_strsub(tab[i], 0, ft_strlen(tab[i]) - 1);
			i++;
		}
		new_tab[i] = NULL;
	}
	else
		new_tab = reducing_tab_part3(tab);
	free_tab(tab);
	return (new_tab);
}
