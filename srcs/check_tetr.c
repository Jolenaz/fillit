/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:22:27 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/17 14:10:52 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <tetriminos.h>

static int	check_voisin(char *tab, int j)
{
	int		i;

	i = 0;
	if (tab[j - 1] == '#' && j > 0)
		i++;
	if (tab[j + 1] == '#')
		i++;
	if (tab[j - 5] == '#' && j >= 5)
		i++;
	if (tab[j + 5] == '#' && j < 15)
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
	if (voisin < 6)
		error("forme de la piece");
	return (1);
}

int			check_tetr(char *buf)
{
	unsigned int	nbp;
	unsigned int	nbh;
	unsigned int	i;

	nbp = 0;
	nbh = 0;
	i = 1;
	while (*buf)
	{
		if (*buf == '.')
			++nbp;
		else if (*buf == '#')
			++nbh;
		else if (*buf == '\n' && ((i - i / 21) % 5) != 0 && (i % 21) != 0)
			error("error position \\n ou nombre de \\n");
		buf++;
		i++;
		if (i % 21 == 0 || *buf == '\0')
			if (nbh != 4 * i / 21 || nbp != 12 * i / 21
					|| !check_piece(buf - 20))
				error("nb de . ou nb de #");
	}
	if (*(buf - 2) == '\n' || i < 20)
		return (0);
	return (1);
}
