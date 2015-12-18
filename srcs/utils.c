/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:33:29 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/18 16:42:38 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#define DEBUG 1

void	error(char *error)
{
	if (DEBUG == 1)
	{
		ft_putstr("\033[38;5;9m Error > ");
		ft_putendl(error);
	}
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}
