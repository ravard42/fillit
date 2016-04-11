#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillist	*all;
	t_fillist	*lst;
	int		n;
	char		**tab;

	if (argc == 2)
	{
		all = load_extern_file_lst();
		lst = load_lst(argv[1], all);
		n = square_initial_size(lst);
		tab = load_tab(n);
		while(iter_next_tetrimino(tab, &lst) == 0)
		{
			free(tab);
			tab = NULL;
			tab = load_tab(n++);
		}
		print_tab(tab);
		free(all);
		free(lst);
		free(tab);
	}
	else
		ft_putstr("usage : ./fillit tetriminos_file\n");
	return (0);
}