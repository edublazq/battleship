#ifndef GAME_HPP
# define GAME_HPP

# include "battleship.hpp"

class Game
{
private:
	Board	_playerBoard;
	Board	_computerBoard;
	bool	_turn;
	int		_turn_count;
	bool	_finished;
public:
	Game(void);

	void	startGame(void);
};

#endif
