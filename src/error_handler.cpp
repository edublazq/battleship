/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:16:32 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/13 11:16:34 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battleship.hpp"

void	puterror(const char *s)
{
	std::cerr << BOLD << RED << s << RESET << std::endl;
}
