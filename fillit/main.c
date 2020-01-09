/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:06:36 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 17:52:13 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int		r;
	int		fd;
	char	buff[2];
	char	*line;

	if (ac != 2)
		write(1, "usage: prog needs 1 (file) argument type .fillit\n", 49);
	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(line = (char *)malloc(sizeof(char))))
		return (0);
	while ((r = read(fd, buff, 1)) > 0)
	{
		buff[r] = 0;
		line = ft_strjoin_free(line, ft_strdup(buff));
	}
	if (test_errors(line) == 0)
	{
		write(1, "error\n", 6);
		free(line);
		return (0);
	}
	main_function(line);
	free(line);
}
