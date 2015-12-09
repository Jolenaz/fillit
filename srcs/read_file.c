/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:01:49 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/09 15:30:45 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21 * 26
#include <fcntl.h>
#include <libft.h>
#include <tetriminos.h>
#include <stdio.h>

static char	*read_file(int fd)
{
	char	*buf;
	int		i;

	i = 0;
	buf = ft_strnew(BUF_SIZE);
	if (buf)
	{
		if (read(fd, buf, BUF_SIZE) != -1)
		{
			if (check_tetr(buf))
				ft_putstr(buf);
			i++;
		}
		ft_putstr("Tetriminos loaded :");
		ft_putnbr(i);
		return (NULL);
	}
	return (0);
}

int		load_file(char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) != -1)
	{
		read_file(fd);
	}
	return (0);
}
