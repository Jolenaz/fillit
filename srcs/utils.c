/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:33:29 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 17:47:37 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#define	DEBUG 1

void	error(char *error)
{
	if (DEBUG == 1)
	{
		ft_putstr("\033[38;5;47m");
		ft_putendl(error);
	}
	else
		ft_putstr("Error");
	exit(EXIT_FAILURE);
}
