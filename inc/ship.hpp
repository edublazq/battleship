/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:33:30 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 00:33:31 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "battleship.hpp"

class	Ship
{
	private:
		int				_size;
		int				_n_hits;
		bool			_dead;
		t_orientation	_orientation;
		t_pos			_pos;
	public:
		explicit Ship(int size, t_orientation orientation, t_pos pos);
		int		getSize(void) const;
		void	setSize(int size);
		t_pos	getPos(void) const;
		void	setPos(t_pos pos);
		void	impact(void);
		bool	isDead(void) const;
		bool	isHere(t_pos pos) const;
};
