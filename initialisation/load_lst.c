/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 00:03:46 by ravard            #+#    #+#             */
/*   Updated: 2016/04/20 12:29:02 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillist		*set_rang(t_fillist *lst)
{
	int	i;

	while (lst->prev)
		lst = lst->prev;
	i = 1;
	lst->rang = i;
	while (lst->next)
	{
		lst = lst->next;
		i++;
		lst->rang = i;
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

static void		fd_error(void)
{
	ft_putstr("failure in the opening of file");
	ft_putchar('\n');
	exit(0);
}

t_fillist		*load_lst(char *file, t_fillist *all)
{
	int			fd;
	int			ret[2];
	char		*buf;
	t_fillist	*lst;
	t_fillist	*lst2;

	if ((fd = open(file, O_RDONLY)) == -1)
		fd_error();
	buf = (char *)malloc(sizeof(char) * 21);
	lst2 = NULL;
	while ((ret[0] = read(fd, buf, 21)))
	{
		ret[1] = ret[0];
		buf[ret[0] - 1] = '\0';
		lst = lst2;
		lst2 = check_and_set(buf, all, lst);
	}
	if (ret[1] == 21)
		error();
	close(fd);
	if (lst2)
		lst2 = set_rang(lst2);
	else
		error();
	return (lst2);
}
