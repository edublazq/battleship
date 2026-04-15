/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:38:08 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 00:38:09 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "battleship.hpp"

class Board
{
	private:
		int								_rows;
		int								_cols;
		int								_n_ships;
		std::vector<std::vector<Box>>	_board;
		std::list<Ship>					_ships;
	public:
		Board();
		Board(int rows, int cols);
		
		int			getRows() const { return _rows; }
		int			getCols() const { return _cols; }

		bool		putShip(int size, t_pos pos, t_orientation orientation);
		bool		everyoneSink(void);
		bool		randPutShip(void);
		bool		shoot(t_pos pos);
		bool		validatePos(t_pos pos);
		void		showBoard(bool flag);
};
