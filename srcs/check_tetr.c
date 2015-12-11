/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:22:27 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 10:13:26 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VAR_GLOBALES
#include <libft.h>
#include <tetriminos.h>

static int	ft_formeexistante(int *j)
{
	int	i;
	int	k;

	i = 4;
	while (i-- >= 0)
		j[i] -= j[0];
	i = 0;
	k = 0;
	while (k < 19)
	{
		i = 0;
		while (i < 4)
		{
			if (j[i] != TABPE[k][i])
				break ;
			i++;
			if (i == 4)
				return (1);
		}
		k++;
	}
	return (0);
}

static int	ft_cf(char *str)
{
	int i;
	int *j;

	i = 0;
	if ((j = (int*)malloc(sizeof(int) * 4)) == NULL)
		return (0);
	while (i < 20)
	{
		if (str[i] == '#')
		{
			*j = i;
			j++;
		}
		i++;
	}
	if (ft_formeexistante(j - 4))
		return (1);
	return (0);
}

int			check_tetr(char *tetr)
{
	unsigned int	nbp;
	unsigned int	nbh;
	unsigned int	i;

	nbp = 0;
	nbh = 0;
	i = 1;
	while (*tetr)
	{
		if (*tetr == '.')
			++nbp;
		else if (*tetr == '#')
			++nbh;
		else if (*tetr == '\n' && ((i - i / 21) % 5) != 0 && (i % 21) != 0)
			return (0);
		tetr++;
		i++;
		if (i % 21 == 0 || *tetr == '\0')
			if (nbh != 4 * i / 21 || nbp != 12 * i / 21 || !ft_cf(tetr - 20))
				return (0);
	}
	if (*(tetr - 2) == '\n')
		return (0);
	return (1);
}
