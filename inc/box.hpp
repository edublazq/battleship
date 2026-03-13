/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:58:26 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/12 23:58:27 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_HPP
# define BOX_HPP

# include "battleship.hpp"

class Box
{
	private:
		t_status	_status;
	public:
		explicit Box();
		void		setStatus(t_status status);
		t_status	getStatus(void) const;
		bool		hasBoat(void) const;
		bool		shoot(void);
		char		toChar(void) const;
};

#endif
