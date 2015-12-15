/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:24:14 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/15 16:55:00 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

int		check_tetr(char *tetr);
void	ft_printres(char **tab);
char	*ft_solve(int **tabpd);
int		**ft_transtab(int **tab, size_t s);

#endif
