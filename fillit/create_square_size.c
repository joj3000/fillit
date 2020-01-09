/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:21:12 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/25 12:41:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fil_char_til_size(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		s[i] = '.';
		i++;
	}
	s[size] = 0;
}

char			**create_square_size(int size)
{
	int		i;
	int		j;
	char	**square;

	i = 0;
	j = 0;
	if (!(square = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	square[size] = NULL;
	while (i < size)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
		fil_char_til_size(square[i], size);
		i++;
	}
	i = 0;
	return (square);
}
