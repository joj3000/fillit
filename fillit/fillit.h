/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:33:39 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/08 18:20:19 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# include "LIBFT/libft.h"

typedef	struct		s_lst
{
	char			**tab;
	int				height;
	int				width;
	struct s_lst	*next;
}					t_lst;

char				**ft_strsplit_max(char const *s, char c, int max);
char				**reducing_tab_to_we(char **tab);
char				**ft_tabdup(char **tab);
char				**ft_strsplit_max(char const *s, char c, int max);
char				**create_square_size(int size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					count_total_tabs(char *s);
int					ct_tabs(char **tab);
int					minimum_square_size(char *s);
int					test_errors(char *s);
int					main_function(char *s);
int					ft_strlen_nopt(char *s);

t_lst				*new_lst_elem(char **given_tab);
t_lst				*lst_pushback_tab(t_lst *list, char **new_tab);
t_lst				*tetro_list(char *s);

void				print_sq(char **square);
void				rev_updt(char **square);
void				free_tab(char **tab);
void				del_all_lst(t_lst **alst);

size_t				ft_strlen(const char *s);

#endif
