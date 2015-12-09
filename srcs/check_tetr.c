/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:22:27 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/09 17:01:07 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		check_tetr(char	*tetr)
{
	unsigned int	nbp;
	unsigned int	nbh;
	unsigned int	nbv;
	unsigned int	i;

	nbp = 0;
	nbh = 0;
	nbv = 0;
	i = 1;
	while(*tetr)
	{
		if (*tetr == '.')
			++nbp;
		else if (*tetr == '#')
			++nbh;
		else if (*tetr == '\n' && ((i - i / 21) % 5) != 0 && (i % 21) != 0 )
			return (0);
		tetr++;
		i++;
		if (i % 21 == 0 || *tetr == '\0')
			if (nbh != 4 * i / 21 || nbp != 12 * i / 21)
				return (0);
	}
	return (1);
}

