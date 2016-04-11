#include "fillit.h"

void			error(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_fillist		*load_extern_file_lst(void)
{
	int		fd;
	char		*buf;
	t_fillist	*lst;
	t_fillist	*lst2;

	if ((fd = open("/Users/avardrobin/fillit/extern_file.txt", O_RDONLY)) == -1)
	{
		ft_putstr("failure in the opening of extern_file\n");
		exit(0);
	}
	buf = (char *)malloc(sizeof(char) * 21);	
	lst2 = NULL;
	while (read(fd, buf, 21))
	{
		buf[20] = '\0';
		lst = lst2;
		lst2 = new_fillist_elem(lst, buf);
	}
	close(fd);
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
			vide ++;
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
