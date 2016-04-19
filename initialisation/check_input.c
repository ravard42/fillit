/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:42:26 by ravard            #+#    #+#             */
/*   Updated: 2016/04/20 00:40:18 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_fillist		*load_extern_file_lst(void)
{
	char		**tab;
	int			i;
	t_fillist	*lst;
	t_fillist	*lst2;

	tab = extern_file();
	lst2 = NULL;
	i = -1;
	while (tab[++i])
	{
		lst = lst2;
		lst2 = new_fillist_elem(lst, tab[i]);
	}
	while (lst2->prev)
		lst2 = lst2->prev;
	lst2 = set_rang(lst2);
	return (lst2);
}

static int		check_one(char *str)
{
	int		i;
	int		vide;
	int		fill;

	i = -1;
	vide = 0;
	fill = 0;
	while (str[++i])
	{
		if (str[i] == '.')
			vide++;
		else if (str[i] == '#')
			fill++;
		if ((i == 4 || i == 9 || i == 14 || i == 19) && str[i] != '\n')
			return (0);
	}
	if (vide != 12 || fill != 4)
		return (0);
	return (1);
}

static int		check_two(t_fillist *all, t_fillist *lst)
{
	while (all)
	{
		if (all->b[0] == lst->b[0] && all->b[1] == lst->b[1] &&
			all->c[0] == lst->c[0] && all->c[1] == lst->c[1] &&
			all->d[0] == lst->d[0] && all->d[1] == lst->d[1])
			return (1);
		all = all->next;
	}
	return (0);
}

t_fillist		*check_and_set(char *buf, t_fillist *all, t_fillist *lst)
{
	if (check_one(buf))
	{
		lst = new_fillist_elem(lst, buf);
		if (check_two(all, lst))
			return (lst);
	}
	error();
	return (NULL);
}
