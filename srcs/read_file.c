/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:01:49 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 17:24:48 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21 * 26
#include <fcntl.h>
#include <libft.h>
#include <tetriminos.h>
#include <stdio.h>

static int	**create_tab(char *buf)
{
	int		**tabpd;
	int		i;
	int		k;
	int		j;
	int		*tmp;

	k = 0;
	i = 0;
	tabpd = malloc(sizeof(int*) * 27);
	if (tabpd == NULL)
		return (NULL);
	while (buf[i])
	{
		tabpd[k] = (int*)malloc(sizeof(int) * 5);
		if (!tabpd[k])
			return (NULL);
		tmp = tabpd[k];
		*tmp++ = i / 21;
		j = 0;
		while (j < 20)
		{
			if (buf[i] == '#')
				*tmp++ = j;
			j++;
			i++;
		}
		i++;
		k++;
	}
	i = 0;
	while (i < 8)
	{
		ft_putstr("tab n: ");
		ft_putnbr(i);
		ft_putchar('\n');
		k = 0;
		while (k < 5)
		{

			ft_putnbr(tabpd[i][k]);
			ft_putstr(", ");
			k++;
		}
		ft_putchar('\n');
		i++;
	}
	return (tabpd);
}

static char	*read_file(int fd)
{
	char	*buf;
	int		i;
	int		**tabpd;

	i = 0;
	buf = ft_strnew(BUF_SIZE);
	if (buf)
	{
		if (read(fd, buf, BUF_SIZE) != -1)
		{
			if (check_tetr(buf))
				tabpd = create_tab(buf);
			else
				ft_putendl("Error");
			i++;
		}
		ft_putstr("Tetriminos loaded :");
		ft_putnbr(i);
		return (NULL);
	}
	return (0);
}

int			load_file(char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) != -1)
	{
		read_file(fd);
	}
	return (0);
}
