#include "game.hpp"

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

void Game::playerTurn(void)
{
    std::string	box;
    t_pos		pos;
    e_status	status;

    do {
        do {
            std::cout << BOLD << "Formato: \"col-row\" ejemplo: 2-7" << RESET << std::endl;
            std::cout << "Casilla para atacar: ";
            std::cin >> box;
			if (box.empty())
				continue ;
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
        std::cout << RED << "Le has dado a un barco!" << RESET << std::endl;
    else if (status == SHOOTED_WATER)
        std::cout << RED << "Has fallado!" << RESET << std::endl;
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
    status = _computerBoard.getStatus(pos);

    if (status == SHOOTED)
        std::cout << RED << "Le ha dado a un barco!" << RESET << std::endl;
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
		playerTurn();
		_computerBoard.showBoard(false);
		computerTurn();
		_playerBoard.showBoard(true);
	}
	showEnd();
}
