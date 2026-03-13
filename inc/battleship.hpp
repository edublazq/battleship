/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battleship.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:01 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 00:00:01 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLESHIP_HPP
# define BATTLESHIP_HPP	
# include <iostream>
# include <cstdlib>
# include <stdexcept>
# include <vector>
# include "box.hpp"
# include "ship.hpp"
# include "board.hpp"

typedef enum e_status
{
	WATER,
	SHIP,
	SHOOTED,
	SHOOTED_WATER	
}	t_status;

typedef enum e_orientation
{
	VERTICAL,
	HORIZONTAL
}	t_orientation;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

#endif
