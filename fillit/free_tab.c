/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:27:14 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 11:12:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

/*
**int main()
**{
**	char *s;
**	char *t;
**	char *u;
**
**	char **S;
**
**	s = ft_strdup("123");
**	t = ft_strdup("456");
**	u = ft_strdup("789");
**
**	S = (char **)malloc(sizeof(char *) * 3 + 1);
**
**	S[0] = s;
**	S[1] = t;
**	S[2] = u;
**	S[3] = NULL;
**
**	int i = 0;
**	free_tab(S);
**	while (S[i] != NULL)
**	{
**		printf("%s\n", S[i]);
**		i++;
**	}
**}
*/
