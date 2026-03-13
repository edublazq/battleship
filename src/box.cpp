/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:09:55 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 00:09:56 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.hpp"

Box::Box()
{
	_status = WATER;
}

void	Box::setStatus(t_status status)
{
	this->_status = status;	
}

t_status	Box::getStatus(void) const
{
	return this->_status;
}

bool	Box::hasBoat(void) const
{
	if (this->getStatus() == SHIP || this->getStatus() == SHOOTED)
		return (true);
	return (false);
}

/* DISCLAIMER: EN LA FUNCION DISPARAR HE PUESTO QUE SI YA HABIAS DISPARADO ANTES
FALLES PORQUE YA ESA CASILLA ESTA MUERTA Y ES INUTIL VOLVER A DISPARAR */

bool	Box::shoot(void)
{
	if (this->getStatus() == SHOOTED || this->getStatus() == SHOOTED_WATER)
		return (false);
	if (this->getStatus() == WATER)
	{
		this->setStatus(SHOOTED_WATER);
		return (false);
	}
	this->setStatus(SHOOTED);
	return (true);
}

char	Box::toChar(void) const
{
	switch(this->getStatus())
	{
		case SHIP:
			return ('B');
			break ;
		case WATER:
			return ('~');
			break ;
		case SHOOTED:
			return ('X');
			break ;
		case SHOOTED_WATER:
			return ('O');
			break ;
	}
	return ('E'); // ESTO NO DEBE PASAR PERO POR SI LLEGA SABER QUE FALLA ALGO
}
