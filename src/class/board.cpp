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

/* Comprobaciones para saber si podemos poner un barco */


/* EDU DEL FUTURO POR FAVOR AÑADE QUE LOS BARCOS NO SE SOLAPEN */
bool	Board::putShip(int size, t_pos pos, t_orientation orientation)
{
	if (size > 4 || size <= 0)
		return (false);
	if (pos.x >= this->_cols || pos.y >= this->_rows)
		return (false);
	if (pos.x < 0 || pos.y < 0)
		return (false);

	//si sumas el size + la pos conoces el final de tu barco
	if (orientation == VERTICAL)
	{
		if (pos.y + size >= _rows)
			return (false);
	}
	else
	{
		if (pos.x + size >= _cols)
			return (false);
	}
	//crear barco y añadirlo a la lista, sumando a n_ships ademas
	Ship	ship(size, orientation, pos);
	
	_n_ships++;
	this->_ships.push_back(ship); //vengo de C y esto es muy comodo
	return (true);
}
