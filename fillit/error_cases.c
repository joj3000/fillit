/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:18:44 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/26 12:25:51 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_line(char *s)
{
	int i;
	int nb_pt;
	int nb_htg;
	int nb_l;

	i = 0;
	nb_pt = 0;
	nb_htg = 0;
	nb_l = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == '\n' || s[i] == '#' || s[i] == '.'))
			return (0);
		else if (s[i] == '.')
			nb_pt++;
		else if (s[i] == '#')
			nb_htg++;
		else if (s[i] == '\n' && s[i + 1] != '\n')
			nb_l++;
		i++;
	}
	if (nb_l % 4 == 0 && nb_pt % 12 == 0 && nb_htg % 4 == 0)
		if ((int)ft_strlen(s) == nb_l + nb_pt + nb_htg + (nb_pt / 12 - 1))
			return (1);
	return (0);
}

static int	valid_tetra(char *s)
{
	int i;
	int nb_touch;

	i = 0;
	nb_touch = 0;
	while (s[i] && i < 20)
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				nb_touch++;
			if ((i - 1) >= 0 && (s[i - 1] == '#'))
				nb_touch++;
			if ((i - 5) >= 0 && (s[i - 5] == '#'))
				nb_touch++;
			if ((i + 5) <= 20 && (i + 5) < (int)ft_strlen(s)
				&& (s[i + 5] == '#'))
				nb_touch++;
		}
		i++;
	}
	if (nb_touch <= 8 && nb_touch >= 6)
		return (1);
	return (0);
}

int			test_errors(char *s)
{
	int n;

	n = 0;
	if (!s)
		return (0);
	if (valid_line(s) == 0)
		return (0);
	while (*s != 0)
	{
		if (*s == '\n' && s[0] != 0)
			s++;
		if (valid_tetra(s) == 0)
			return (0);
		while (n < 20)
		{
			s++;
			n++;
		}
		n = 0;
	}
	return (1);
}
