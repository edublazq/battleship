#include "game.hpp"

static bool	isSunk(Board &board, t_pos start)
{
	if (board.getStatus(start) != SHOOTED)
		return (false);

	t_pos							neighbors[4];
	t_pos							current;
	std::vector<std::vector<bool> >	visited(board.getRows(), std::vector<bool>(board.getCols(), false));
	std::vector<t_pos>				stack;

	stack.push_back(start);
	while (!stack.empty())
	{
		current = stack.back();
		stack.pop_back();
		if (current.x < 0 || current.y < 0 || current.x >= board.getCols() || current.y >= board.getRows())
			continue;
		if (visited[current.y][current.x])
			continue;
		if (board.getStatus(current) != SHOOTED)
			continue;
		visited[current.y][current.x] = true;
		neighbors[0] = {current.x + 1, current.y};
		neighbors[1] = {current.x - 1, current.y};
		neighbors[2] = {current.x, current.y + 1};
		neighbors[3] = {current.x, current.y - 1};
		for (uint8_t i = 0; i < 4; i++)
		{
			t_pos		next = neighbors[i];
			if (next.x < 0 || next.y < 0 || next.x >= board.getCols() || next.y >= board.getRows())
				continue;
			t_status	status = board.getStatus(next);
			if (status == SHIP)
				return (false);
			if (status == SHOOTED && !visited[next.y][next.x])
				stack.push_back(next);
		}
	}
	return (true);
}

Game::Game(void)
{
	if (_playerBoard.randPutShip() == false)
	{
		puterror("Error while creating player board");
		return ;
	}
	if (_computerBoard.randPutShip() == false)
	{
		puterror("Error while creating computer board");
		return ;
	}
}

bool	Game::checkEnd(void)
{
	if (_playerBoard.everyoneSink() == true)
		return (true);
	if (_computerBoard.everyoneSink() == true)
		return (true);
	return (false);
}

bool Game::playerTurn(void)
{
    std::string	box;
    t_pos		pos;
    e_status	status;

    do {
        do {
            std::cout << BOLD << "Formato: \"col-row\" ejemplo: 2-7" << RESET << std::endl;
            std::cout << "Casilla para atacar: ";
            if (!(std::cin >> box) || std::cin.eof() == true)
			{
				std::cout << std::endl;
				std::cout << GREEN << BOLD << "Muchas gracias por jugar!" << RESET << std::endl;
				return (false);
			}
			if (box.empty())
			{
				std::cin.clear();
				continue ;
			}
            if (box.size() != 3 || !isdigit(box[0]) || box[1] != '-' || !isdigit(box[2]))
            {
                std::cout << RED << "FORMATO INVALIDO" << RESET << std::endl;
                continue;
            }

        } while (box.size() != 3 || !isdigit(box[0]) || box[1] != '-' || !isdigit(box[2]));
        pos.x = box[0] - '0';
        pos.y = box[2] - '0';
    } while (_computerBoard.shoot(pos) == false);

    status = _computerBoard.getStatus(pos);

	if (status == SHOOTED)
	{
		if (isSunk(_computerBoard, pos))
			std::cout << RED << "Le has hundido un barco!" << RESET << std::endl;
		else
			std::cout << RED << "Le has dado a un barco!" << RESET << std::endl;
	}
    else
	{
        std::cout << RED << "Has fallado!" << RESET << std::endl;
	}
	return (true);
}

void	Game::computerTurn()
{
	t_pos		pos;
	e_status	status;

	do
	{
		pos.x = std::rand() % 10;
		pos.y = std::rand() % 10;
	} while (_playerBoard.shoot(pos) == false);

	std::cout << "El ordenador ha disparado a " << pos.x << "-" << pos.y << "!" << std::endl;
	status = _playerBoard.getStatus(pos);

	if (status == SHOOTED)
	{
		if (isSunk(_playerBoard, pos))
			std::cout << RED << "Te ha hundido un barco!" << RESET << std::endl;
		else
			std::cout << RED << "Le ha dado a un barco!" << RESET << std::endl;
	}
    else if (status == SHOOTED_WATER)
        std::cout << RED << "Ha fallado!" << RESET << std::endl;
}

void	Game::showEnd()
{
	if (_playerBoard.everyoneSink())
		std::cout << RED << BOLD << "Has perdido, más suerte la próxima" << RESET << std::endl;
	else
		std::cout << GREEN << BOLD << "Has ganado! Muchas gracias por jugar" << RESET << std::endl;
}

void	Game::startGame()
{
	if (this->_computerBoard.randPutShip())
		std::cout << "estan bien puestos" << std::endl;
	this->_playerBoard.randPutShip();
	while (checkEnd() == false)
	{
		if (!playerTurn())
			return ;
		_computerBoard.showBoard(false);
		computerTurn();
		_playerBoard.showBoard(true);
	}
	showEnd();
}
