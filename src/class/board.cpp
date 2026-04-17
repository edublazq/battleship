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

static bool	randShipManager(Board *board, int size)
{
	bool		control;
	int			attempt;
	t_pos		pos;

	control = false;
	attempt = 0;
	while (!control && attempt < 1000)
	{
		pos.x = std::rand() % board->getCols();
		pos.y = std::rand() % board->getRows();
		if (board->putShip(size, pos, HORIZONTAL))
			control = true;
		else if (control == board->putShip(size, pos, VERTICAL))
			control = true;
		attempt++;
	}
	if (attempt == 1000)
	{
		puterror("Impossible to put the ships");
		return (false);
	}
	return (true);
}

bool	Board::randPutShip(void)
{
	if (!randShipManager(this, 4))
		return (false);
	for (uint8_t i = 0; i < 2; i++)
		if (!randShipManager(this, 3))
			return (false);
	for (uint8_t i = 0; i < 3; i++)
		if (!randShipManager(this, 2))
			return (false);
	for (uint8_t i = 0; i < 4; i++)
		if (!randShipManager(this, 1))
			return (false);
	return (true);
}

bool	Board::shoot(t_pos pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= _cols || pos.y >= _rows)
		return (false);
	if (_board[pos.x][pos.y].getStatus() == WATER)
	{
		_board[pos.x][pos.y].setStatus(SHOOTED_WATER);
		return (true);
	}
	if (_board[pos.x][pos.y].getStatus() == SHIP)
	{
		_board[pos.x][pos.y].setStatus(SHOOTED);
		return (true);
	}
	return (false);
}

bool	Board::everyoneSink(void)
{
	for (std::list<Ship>::iterator i = _ships.begin(); i != _ships.end(); i++)
	{
		if (!i->isDead())
			return (false);
	}
	return (true);
}

void	Board::showBoard(bool flag)
{
	if (flag == true)
	{
		for (int i = 0; i < getRows(); i++)
		{
			for (int j = 0; j < getCols(); j++)
			{
				std::cout << GREEN << _board[i][j].toChar() << RESET;
			}
			std::cout << std::endl;
		}
	}
	if (flag == false)
	{
		char	c;

		for (int i = 0; i < getRows(); i++)
		{
			for (int j = 0; j < getCols(); j++)
			{
				c = _board[i][j].toChar();
				if (c != 'B')
					std::cout << GREEN << _board[i][j].toChar() << RESET;
				else
					std::cout << GREEN << "~" << RESET;
			}
			std::cout << std::endl;
		}
	}
}

bool	Board::validatePos(t_pos pos)
{
	if (pos.x < getCols() && pos.y < getRows())
		return (true);
	return (false);
}
