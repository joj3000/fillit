/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:14:50 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/26 12:32:21 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_char_c(char str_c, char c)
{
	if (str_c == c)
		return (1);
	return (0);
}

int			ft_strlen_str(char const *str, int i, char c, int max)
{
	int j;

	j = 0;
	while (!ft_check_char_c(str[i], c) && str[i] != '\0' && i < max)
	{
		j++;
		i++;
	}
	return (j);
}

int			ft_nb_str(char const *str, char c, int max)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0' && i < max)
	{
		if (ft_check_char_c(str[i], c) == 0 && str[i] != '\0')
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
		}
		if (ft_check_char_c(str[i], c) == 1 && str[i] != '\0')
			flag = 0;
		i++;
	}
	return (count);
}

char		*ft_strcpy_char(char const *str, char c, int i, int max)
{
	char	*cpy;
	int		j;

	j = 0;
	if (!(cpy = malloc(sizeof(char) * ft_strlen_str(str, i, c, max) + 1)))
		return (NULL);
	while (str[i] && i < max && ft_check_char_c(str[i], c) == 0)
	{
		cpy[j] = str[i];
		i++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char		**ft_strsplit_max(char const *s, char c, int max)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!c || !s)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (ft_nb_str(s, c, max) + 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_nb_str(s, c, max) && i < max)
	{
		while (ft_check_char_c(s[i], c) == 1)
			i++;
		tab[j] = ft_strcpy_char(s, c, i, max);
		j++;
		i++;
		while (s[i] != '\0' && ft_check_char_c(s[i], c) == 0)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
