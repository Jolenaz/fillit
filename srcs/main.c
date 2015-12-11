/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:24:38 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 10:08:37 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <read.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl("Error");
	else
		load_file(argv[1]);
	return (1);
}
