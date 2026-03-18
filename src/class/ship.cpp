/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:52:50 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 00:52:50 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ship.hpp"

Ship::Ship(int size, t_orientation orientation, t_pos pos)
{
	_size = size;
	_orientation = orientation;
	_pos = pos;
	_dead = false;
	_n_hits = 0;
}

int	Ship::getSize(void) const
{
	return (this->_size);
}

void	Ship::setSize(int size)
{
	this->_size = size;
}

t_pos	Ship::getPos(void) const
{
	return (this->_pos);
}

void	Ship::setPos(t_pos pos)
{
	this->_pos = pos;
}

void	Ship::impact(void)
{
	(this->_n_hits)++;
	if (this->_n_hits >= this->_size)
		this->_dead = true;
}

bool	Ship::isDead(void) const
{
	return (this->_dead);
}

bool	Ship::isHere(t_pos pos) const
{
	if (_pos.x == pos.x && _pos.y == pos.y)
		return (true);
	return (false);
}
