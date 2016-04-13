/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:00:18 by ravard            #+#    #+#             */
/*   Updated: 2016/04/13 15:00:19 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		next_pos(char **tab, t_fillist *lst)
{
	lst->a_abs[0] = 0;
	while (tab[lst->a_abs[0]])
	{
		lst->a_abs[1] = 0;
		while (tab[lst->a_abs[0]][lst->a_abs[1]])
		{
			if (check_tetrimino(tab, lst))
			{
				set_tetrimino(tab, lst);
				return (1);
			}
			lst->a_abs[1]++;
		}
		lst->a_abs[0]++;
	}
	return (0);
}

static int		backtrack_next_pos(char **tab, t_fillist *lst)
{
	rm_tetrimino(tab, lst);
	lst->a_abs[1]++;
	while (tab[lst->a_abs[0]])
	{
		while (tab[lst->a_abs[0]][lst->a_abs[1]])
		{
			if (check_tetrimino(tab, lst) == 1)
			{
				set_tetrimino(tab, lst);
				return (1);
			}
			lst->a_abs[1]++;
		}
		lst->a_abs[0]++;
		lst->a_abs[1] = 0;
	}
	return (0);
}

static int		next_tetrimino(char **tab, t_fillist **lst)
{
	while (*lst != NULL && next_pos(tab, *lst) == 1)
		*lst = (*lst)->next;
	if (*lst == NULL)
		return (1);
	else
	{
		while ((*lst)->rang != 1 && !(backtrack_next_pos(tab, (*lst)->prev)))
			*lst = (*lst)->prev;
		if ((*lst)->rang == 1)
			return (0);
		else
			return (42);
	}
}

int				iter_next_tetrimino(char **tab, t_fillist **lst)
{
	int		ret;

	while ((ret = next_tetrimino(tab, lst)) == 42)
		;
	if (ret == 0)
		return (0);
	else
		return (1);
}
