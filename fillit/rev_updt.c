/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_updt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:36:11 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 11:37:48 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	letter_to_del(char **square)
{
	int		i;
	int		j;
	char	letter_to_del;

	i = 0;
	j = 0;
	letter_to_del = 'A';
	while (square[i] != NULL)
	{
		while (square[i][j] != 0)
		{
			if (square[i][j] != '.' && square[i][j] > letter_to_del)
				letter_to_del = square[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (letter_to_del);
}

void		rev_updt(char **square)
{
	int		i;
	int		j;
	char	letter_to_delete;

	i = 0;
	j = 0;
	letter_to_delete = letter_to_del(square);
	while (square[i] != NULL)
	{
		while (square[i][j] != 0)
		{
			if (square[i][j] == letter_to_delete)
				square[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
