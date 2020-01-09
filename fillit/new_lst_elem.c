/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:48:36 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/26 12:33:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*new_lst_elem(char **given_tab)
{
	t_lst	*elem;

	if (!(elem = malloc(sizeof(t_lst))))
		return (NULL);
	elem->tab = given_tab;
	elem->height = ct_tabs(given_tab);
	elem->width = (int)ft_strlen(given_tab[0]);
	elem->next = NULL;
	return (elem);
}
