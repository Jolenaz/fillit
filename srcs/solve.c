/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:20:13 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/15 18:40:30 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>
#include <tetriminos.h>



static size_t	size_min(int **tabpd)
{
	int		i;
	int		res;

	res = 1;
	i = 0;
	while (*tabpd[i] != -1)
		i++;
	while ((res * res) <= (i * 4))
	{
		if ((res * res) == (i * 4))
			return (res);
		res++;
	}
	return (res - 1);
}

static int	ft_placepiece(char *grille, int **tabpd, int i)
{
	int	j;
	int	k;

	j = 1;
	k = 0;
	if (tabpd[i][0] == -1)
		return (1);
	while (grille[k])
	{
		while (j < 5)
		{
			ft_putstr(".");
			if (grille[tabpd[i][j] + k] != '.')
				break;
			j++;
		}
		if (j != 5)
			k++;
		else
		{
			j = 1;
			while (j < 5)
			{
				ft_putnbr(1);
				grille[tabpd[i][j] + k] = tabpd[i][0] + 'A';
				j++;
			}
			if (ft_placepiece(grille, tabpd, i+1))
			{
				j = 1;
				while (j < 5)
				{
					ft_putnbr(2);
					grille[tabpd[i][j]+ k]  = '.';
					j++;
				}
				ft_putnbr(2);
			}
			else
				return (1);
		}
		k++;
	}
	return (0);
}


static char	*resolve(int **tabpd, size_t s)
{
	char				*grille;
	unsigned int		i;

	i = 0;
	if ((grille = ft_strnew((s * s) + s)) == NULL)
		error("malloc failed dans resolve");
	while (i < ((s * s) + s))
	{
		if (((i + 1) % (s + 1)) == 0)
			grille[i] = '\n';
		else
			grille[i] = '.';
		i++;
	}
	ft_putstr(grille);
	if (ft_placepiece(grille, tabpd, 0))
		return(grille);
	return(NULL);

}

char	*ft_solve(int **tabpd)
{
	size_t	s;
	char	*resultat;

	s = size_min(tabpd);
	while ((resultat = resolve(ft_transtab(tabpd , s), s)) == NULL)
		s++;
	return (resultat);
}
