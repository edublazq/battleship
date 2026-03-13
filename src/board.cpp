/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:06:02 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 11:06:07 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.hpp"

/* Constructor basico */

Board::Board()
{
	_rows = 10;
	_cols = 10;
	//Inicialización de un array bidimensional con la libreria vector
	_board = std::vector<std::vector<Box>>(_rows, std::vector<Box>(_cols));
}

/* Constructor con sobrecarga para inicializar con distintas rows y cols */

Board::Board(int rows, int cols)
{
	_rows = rows;
	_cols = cols;
	_board = std::vector<std::vector<Box>>(_rows, std::vector<Box>(_cols));
}

bool	Board::putShip(int size, t_pos pos, t_orientation orientation)
{
	if (size < 2)
	{
		puterror("Not enough size");
		return (false);
	}
	if ()
}
