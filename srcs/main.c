/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:24:38 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/17 14:15:02 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <read.h>
#include <utils.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		error("Fillit require juste one argument !");
	else
	{
		if (!load_file(argv[1]))
			error("Probleme au chargement du fichier");
	}
	return (1);
}
