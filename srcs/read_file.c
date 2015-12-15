/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:01:49 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/15 17:15:05 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21 * 26
#include <fcntl.h>
#include <libft.h>
#include <tetriminos.h>
#include <utils.h>

static void	creat_piece(char *buf, int *i, int *tmp)
{
	int j;

	j = 0;
	while (j < 20)
	{
		if (buf[*i] == '#')
			*tmp++ = j;
		(*i)++;
		j++;
	}
}

static int	**create_tab(char *buf)
{
	int		**tabpd;
	int		i;
	int		k;
	int		*tmp;

	k = 0;
	i = 0;
	if ((tabpd = malloc(sizeof(int*) * 27)) == NULL)
		return (NULL);
	while (buf[i])
	{
		if ((tabpd[k] = (int*)malloc(sizeof(int) * 5)) == NULL)
			return (NULL);
		tmp = tabpd[k];
		*tmp++ = i / 21;
		creat_piece(buf, &i, tmp);
		i++;
		k++;
	}
	if ((tabpd[k] = (int*)malloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	tabpd[k][0] = -1;
	return (tabpd);
}

static int **read_file(int fd)
{
	char	*buf;

	buf = ft_strnew(BUF_SIZE);
	if (buf)
	{
		if (read(fd, buf, BUF_SIZE) != -1)
		{
			if (check_tetr(buf))
				return (create_tab(buf));
			else
				ft_putendl("Error");
		}
	}
	return (NULL);
}

int			load_file(char *file_name)
{
	int		fd;
	int		**tabpd;

	if ((fd = open(file_name, O_RDONLY)) != -1)
	{
		if ((tabpd = read_file(fd)) == NULL)
			error("pas de creation de tabpd dans load_file");
		ft_putstr(ft_solve(tabpd));
	}
	return (0);
}
