/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:13:45 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/18 19:13:46 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battleship.hpp"

int	main(void)
{
	Game	game;

	//Inicializamos el random a la hora actual para que los barcos cambien en cada partida
	std::srand(std::time(nullptr));

	std::cout << BOLD << GREEN << "=====================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "     BIENVENIDO A BATTLESHIP" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=====================================" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << "REGLAS BASICAS:" << RESET << std::endl;
	std::cout << "1. Tu objetivo es hundir todos los barcos del ordenador." << std::endl;
	std::cout << "2. El tablero es de 10x10 casillas (columna 0-9, fila 0-9)." << std::endl;
	std::cout << "3. Turno del jugador: Introduce coordenadas en formato 'col-fila' (ej: 2-7)" << std::endl;
	std::cout << "4. El ordenador disparara despues." << std::endl;
	std::cout << "5. Barcos:" << std::endl;
	std::cout << "   - 1 Portaaviones (tamaño 4)" << std::endl;
	std::cout << "   - 2 Acorazados (tamaño 3)" << std::endl;
	std::cout << "   - 3 Destructores (tamaño 2)" << std::endl;
	std::cout << "   - 4 Lanchas (tamaño 1)" << std::endl;
	std::cout << "6. Los barcos estan separados a distancia minima de 1 casilla." << std::endl;
	std::cout << "7. Primero en hundir todos los barcos del rival gana!" << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << "Indicadores del tablero:" << RESET << std::endl;
	std::cout << "   ~ = Agua sin disparos" << std::endl;
	std::cout << "   O = Agua donde disparaste" << std::endl;
	std::cout << "   X = Barco impactado" << std::endl;
	std::cout << "   B = Tu barco (solo ves el tuyo)" << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "=====================================" << RESET << std::endl;
	std::cout << std::endl;

	game.startGame();
}
