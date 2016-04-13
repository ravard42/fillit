/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:57:26 by ravard            #+#    #+#             */
/*   Updated: 2016/04/13 14:57:29 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rm_tetrimino(char **tab, t_fillist *lst)
{
	tab[lst->a_abs[0]][lst->a_abs[1]] = '.';
	tab[lst->a_abs[0] + lst->b[0]][lst->a_abs[1] + lst->b[1]] = '.';
	tab[lst->a_abs[0] + lst->c[0]][lst->a_abs[1] + lst->c[1]] = '.';
	tab[lst->a_abs[0] + lst->d[0]][lst->a_abs[1] + lst->d[1]] = '.';
}
