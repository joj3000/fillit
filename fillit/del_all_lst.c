/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:34:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 16:08:26 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		lst_delone(t_lst **alst)
{
	free_tab((*alst)->tab);
	free(*alst);
	*alst = NULL;
}

void			del_all_lst(t_lst **alst)
{
	t_lst *temp;

	while (*alst)
	{
		temp = (*alst)->next;
		lst_delone(alst);
		*alst = temp;
	}
}
