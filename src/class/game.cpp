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

void	Game::startGame()
{
	
}
