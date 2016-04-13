/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fillist_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 23:48:28 by ravard            #+#    #+#             */
/*   Updated: 2016/04/13 14:56:49 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_var(t_fillist *lst)
{
	lst->a_abs = (int *)malloc(sizeof(int) * 2);
	lst->b = (int *)malloc(sizeof(int) * 2);
	lst->c = (int *)malloc(sizeof(int) * 2);
	lst->d = (int *)malloc(sizeof(int) * 2);
}

static void		set_var_r(int *increm, int *abs, int *var_r)
{
	var_r[0] = increm[2] - abs[0];
	var_r[1] = increm[1] - abs[1];
}

static void		set_var(int *increm, t_fillist *lst)
{
	if (increm[0] == 0)
	{
		lst->a_abs[0] = increm[2];
		lst->a_abs[1] = increm[1];
	}
	else if (increm[0] == 1)
		set_var_r(increm, lst->a_abs, lst->b);
	else if (increm[0] == 2)
		set_var_r(increm, lst->a_abs, lst->c);
	else if (increm[0] == 3)
	{
		set_var_r(increm, lst->a_abs, lst->d);
		lst->a_abs[0] = 0;
		lst->a_abs[1] = 0;
	}
	increm[0]++;
}

static void		trade_tetrimino(t_fillist *lst, char *content)
{
	int	*increm;

	increm = (int *)malloc(sizeof(int) * 3);
	init_var(lst);
	if (lst->a_abs && lst->b && lst->c && lst->d)
	{
		increm[0] = 0;
		increm[1] = 0;
		increm[2] = 0;
		while (increm[0] != 4)
		{
			if (*content == '#')
				set_var(increm, lst);
			if (*content == '\n')
			{
				increm[2]++;
				increm[1] = 0;
			}
			else
				increm[1]++;
			content++;
		}
	}
	else
		ft_putstr("allocation error");
}

t_fillist		*new_fillist_elem(t_fillist *list_prev, char *content)
{
	t_fillist	*tmp;

	tmp = (t_fillist *)malloc(sizeof(t_fillist));
	if (tmp)
	{
		trade_tetrimino(tmp, content);
		tmp->prev = list_prev;
		if (list_prev)
			list_prev->next = tmp;
		tmp->next = NULL;
	}
	return (tmp);
}
