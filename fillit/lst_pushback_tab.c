/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:30:26 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/26 12:32:41 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst				*lst_pushback_tab(t_lst *list, char **new_tab)
{
	t_lst *temp;

	temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_lst_elem(new_tab);
	return (list);
}
