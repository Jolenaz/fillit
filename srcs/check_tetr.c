/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:22:27 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 17:41:29 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tetriminos.h>

static int	check_voisin(char *tab, int j)
{
	int		i;

	i = 0;
	if (tab[j - 1] == '#')
		i++;
	if (tab[j + 1] == '#')
		i++;
	if (tab[j - 5] =='#' && j > 5)
		i++;
	if (tab[j + 5] =='#' && j < 15)
		i++;
	return (i);
}

static int	check_piece(char *str)
{
	int		i;
	int		voisin;

	i = 0;
	voisin = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			voisin += check_voisin(str, i);
		i++;
	}
	if (voisin > 5)
		return (1);
	return (0);
}

int			check_tetr(char *tab)
{
	unsigned int	nbp;
	unsigned int	nbh;
	unsigned int	i;

	nbp = 0;
	nbh = 0;
	i = 1;
	while (*tab)
	{
		if (*tab == '.')
			++nbp;
		else if (*tab == '#')
			++nbh;
		else if (*tab == '\n' && ((i - i / 21) % 5) != 0 && (i % 21) != 0)
			return (0);
		tab++;
		i++;
		if (i % 21 == 0 || *tab == '\0')
			if (nbh != 4 * i / 21 || nbp != 12 * i / 21
					|| !check_piece(tab - 20))
				return (0);
	}
	if (*(tab - 2) == '\n')
		return (0);
	return (1);
}
