#include "fillit.h"

int	check_tetrimino(char **tab, t_fillist *lst)
{
	if (tab[lst->a_abs[0]] &&
		tab[lst->a_abs[0] + lst->b[0]] &&
		tab[lst->a_abs[0] + lst->c[0]] &&
		tab[lst->a_abs[0] + lst->d[0]] &&
		tab[lst->a_abs[0]][lst->a_abs[1]] &&
		tab[lst->a_abs[0] + lst->b[0]][lst->a_abs[1] + lst->b[1]] &&
		tab[lst->a_abs[0] + lst->c[0]][lst->a_abs[1] + lst->c[1]] &&
		tab[lst->a_abs[0] + lst->d[0]][lst->a_abs[1] + lst->d[1]])
	{
		if (tab[lst->a_abs[0]][lst->a_abs[1]] == '.' &&
			tab[lst->a_abs[0] + lst->b[0]][lst->a_abs[1] + lst->b[1]] == '.' &&
			tab[lst->a_abs[0] + lst->c[0]][lst->a_abs[1] + lst->c[1]] == '.' &&
			tab[lst->a_abs[0] + lst->d[0]][lst->a_abs[1] + lst->d[1]] == '.')
			return (1);
	}
	return (0);
}
