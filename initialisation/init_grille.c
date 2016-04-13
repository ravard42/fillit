/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grille.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:54:44 by ravard            #+#    #+#             */
/*   Updated: 2016/04/13 14:54:45 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_initial_size(t_fillist *lst)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	j = 2;
	k = 4;
	while (k < i * 4)
	{
		j++;
		k = j * j;
	}
	return (j);
}

char	**load_tab(int square_size)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * (square_size + 1));
	i = 0;
	while (i < square_size)
	{
		tab[i] = (char *)malloc(sizeof(char) * (square_size + 1));
		j = 0;
		while (j < square_size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
