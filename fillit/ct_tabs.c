/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct_tabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:07:44 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/25 13:07:49 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ct_tabs(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
