/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:33:29 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 18:23:44 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#define	DEBUG 1

void	error(char *error)
{
	if (DEBUG == 1)
	{
		ft_putstr("\033[38;5;9m Error > ");
		ft_putendl(error);
	}
	else
		ft_putendl("Error");
	exit(EXIT_FAILURE);
}
