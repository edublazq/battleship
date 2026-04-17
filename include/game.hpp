#ifndef GAME_HPP
# define GAME_HPP

# include "board.hpp"
# include "types.hpp"

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
	bool	checkEnd(void);
	void	playerTurn(void);
	void	computerTurn(void);
	void	showEnd(void);
};

#endif
