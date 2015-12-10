/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:24:14 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/10 18:01:00 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

/*int	tabpe[3][4] = {
		{0, 4, 5, 10}, // Tvetical gauche
		{0, 1, 6, 7}, // Zhorizontal
		{0, 1, 5, 6} // carre
		};
*/
int		check_tetr(char *tetr);

typedef struct s_piece
{
	const int		p1;
	const int		p2;
	const int		p3;
	const int		p4;
}				t_piece;

#endif
