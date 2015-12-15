/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:32:46 by jbelless          #+#    #+#             */
/*   Updated: 2015/12/15 15:33:04 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

static void	ft_init(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 27)
	{
		j = 0;
		while (j < 5)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	**ft_intnewtab(void)
{
	int i;
	int **res;

	i = 0;
	res = NULL;
	if ((res = (int**)malloc(sizeof(int*) * 27)) == NULL)
		return (NULL);
	while (i < 27)
	{
		if ((res[i] = (int*)malloc(sizeof(int) * 5)) == NULL)
			return (NULL);
		i++;
	}
	ft_init(res);
	return (res);
}

int			**ft_transtab(int **tab, size_t s)
{
	int **res;
	int	i;
	int	j;
	int k;

	i = 0;
	if ((res = ft_intnewtab()) == NULL)
		return (NULL);
	while (tab[i][0] != -1)
	{
		res[i][0] = tab[i][0];
		k = 0;
		j = 1;
		while (++j < 5)
		{
			if (tab[i][j] == tab[i][j - 1] + 1)
				res[i][j] = tab[i][j] % 4 + k * s;
			else
				res[i][j] = tab[i][j] % 4 + ++k * s;
		}
		i++;
	}
	tab[i][0] = -1;
	return (res);
}
