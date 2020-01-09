/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:24:41 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/26 12:46:35 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_sq(char **square)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (square[i] != NULL)
	{
		while (square[i][j] != 0)
		{
			write(1, &square[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}