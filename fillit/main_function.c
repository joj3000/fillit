/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:09:07 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 18:15:36 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fit_at_xy_in_sq(char **square, char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((x + (int)ft_strlen_nopt(tab[0]) > (int)ft_strlen(square[0]) ||
		(y + ct_tabs(tab) > ct_tabs(square))))
		return (0);
	else
		while (tab[i] != NULL)
		{
			while (tab[i][j])
			{
				if (square[y + i][x + j] != '.' && tab[i][j] != '.')
					return (0);
				j++;
			}
			i++;
			j = 0;
		}
	return (1);
}

static char		**updt_sq(char **square, char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != 0)
		{
			if (!(tab[i][j] == '.'))
				square[y + i][x + j] = tab[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (square);
}

static int		rec_pos(t_lst *lst, char **sq, int x, int y)
{
	while (x <= (int)ft_strlen(sq[0]) - 1 && (y <= ct_tabs(sq) - 1))
	{
		while (x < (int)ft_strlen(sq[0]))
		{
			if ((x == (int)ft_strlen(sq[0]) - 1) && (y == ct_tabs(sq) - 1))
				return (0);
			if (fit_at_xy_in_sq(sq, lst->tab, x, y) == 1 && lst->next == NULL)
			{
				updt_sq(sq, lst->tab, x, y);
				print_sq(sq);
				free_tab(sq);
				del_all_lst(&lst);
				exit(0);
			}
			if (fit_at_xy_in_sq(sq, lst->tab, x, y) == 1 && lst->next != NULL)
				if (rec_pos(lst->next, updt_sq(sq, lst->tab, x, y), 0, 0) == 0)
					rev_updt(sq);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int				main_function(char *s)
{
	int			size;
	t_lst		*tetro;
	char		**tab;

	tetro = tetro_list(s);
	size = 2;
	while (1)
	{
		tab = create_square_size(size);
		rec_pos(tetro, tab, 0, 0);
		free_tab(tab);
		size++;
	}
	return (1);
}
