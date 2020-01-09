/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:29:25 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 11:26:10 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**tab_dup;

	i = 0;
	if (!(tab_dup = (char **)malloc(sizeof(char *) * ct_tabs(tab) + 1)))
		return (NULL);
	while (tab[i] != NULL)
	{
		tab_dup[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_dup[i] = NULL;
	free_tab(tab);
	return (tab_dup);
}
