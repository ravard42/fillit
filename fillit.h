/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 23:31:57 by ravard            #+#    #+#             */
/*   Updated: 2016/04/20 00:36:03 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct		s_fillist
{
	int					rang;
	int					*a_abs;
	int					*b;
	int					*c;
	int					*d;
	struct s_fillist	*prev;
	struct s_fillist	*next;
}					t_fillist;

t_fillist			*new_fillist_elem(t_fillist *list_prev, char *content);
t_fillist			*set_rang(t_fillist *lst);
char				**extern_file(void);
t_fillist			*load_extern_file_lst(void);
void				error(void);
t_fillist			*check_and_set(char *buf, t_fillist *all, t_fillist *lst);
t_fillist			*load_lst(char *file, t_fillist *all);
void				print_lst(t_fillist *lst);

int					square_initial_size(t_fillist *lst);
char				**load_tab(int square_size);
void				print_tab(char **tab);

int					check_tetrimino(char **tab, t_fillist *lst);
void				set_tetrimino(char **tab, t_fillist *lst);
void				rm_tetrimino(char **tab, t_fillist *lst);

int					iter_next_tetrimino(char **tab, t_fillist **lst);

#endif
