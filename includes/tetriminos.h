/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:24:14 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/11 09:58:57 by jbelless         ###   ########.fr       */
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

#ifdef VAR_GLOBALES

int	TABPE[19][4] = {
	{0, 1, 5, 6}, // Carre
	{0, 5, 10, 15}, // I vertical
	{0, 1, 2, 3}, // I horizontal
	{0, 5, 4, 10}, // T vetical gauche
	{0, 4, 5, 10}, // T vetical droite
	{0, 4, 5, 6}, // T horizontal haut
	{0, 1, 2, 6}, // T horizontal bas
	{0, 5, 10, 11}, // L vertical droit
	{0, 1, 6, 11}, // L vertical gauche
	{0, 3, 4, 5}, // L horizontal haut
	{0, 1, 2, 5}, // L horizontal bas
	{0, 5, 9, 10}, // J vertical gauche
	{0, 1, 5, 10}, // J vertical droit
	{0, 5, 6, 7}, // J horizontal haut
	{0, 1, 2, 7}, // J horizontal bas
	{0, 4, 5, 9}, // Z vertical
	{0, 1, 6, 7}, // Z horizontal
	{0, 5, 6, 11}, // S vetical
	{0, 1, 4, 5} // S horizontal
};

# else
	extern int TABPE[19][4];
# endif

//typedef struct s_piece
//{
//	const int		p1;
//	const int		p2;
//	const int		p3;
//	const int		p4;
//}				t_piece;

#endif
