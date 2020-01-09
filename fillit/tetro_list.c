/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:59:18 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 15:39:56 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		replace_old_to_char(char **tab)
{
	int			i;
	int			j;
	static char	c = 'A';

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = c;
			j++;
		}
		j = 0;
		i++;
	}
	c++;
	return ;
}

static char		**reduce_it_max(char **tab)
{
	int i;
	int flag;

	i = 0;
	flag = 3;
	while (flag > 0)
	{
		tab = reducing_tab_to_we(tab);
		flag--;
	}
	return (tab);
}

static void		to_bigtab_part2(char *s, int *j)
{
	while (s[*j])
	{
		if (s[*j] == '\n' && s[*j + 1] == '\n')
		{
			*j = *j + 2;
			break ;
		}
		*j = *j + 1;
	}
	return ;
}

static char		***to_bigtab(char *s)
{
	char	**temp;
	char	***big_tab;
	int		j;
	int		i;
	int		nb;

	nb = count_total_tabs(s);
	big_tab = (char ***)malloc(sizeof(char**) * count_total_tabs(s) + 1);
	j = 0;
	i = 0;
	while (nb > 0)
	{
		temp = ft_strsplit_max(&(s[j]), '\n', 20);
		temp = reduce_it_max(reducing_tab_to_we(temp));
		replace_old_to_char(temp);
		big_tab[i] = ft_tabdup(temp);
		to_bigtab_part2(s, &j);
		i++;
		nb--;
	}
	big_tab[i] = NULL;
	return (big_tab);
}

t_lst			*tetro_list(char *s)
{
	char		***big_tab;
	int			i;
	t_lst		*tetro_list;

	i = 1;
	big_tab = to_bigtab(s);
	tetro_list = new_lst_elem(big_tab[0]);
	while (big_tab[i] != NULL)
	{
		lst_pushback_tab(tetro_list, big_tab[i]);
		i++;
	}
	return (tetro_list);
}
