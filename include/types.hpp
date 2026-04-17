#ifndef TYPES_HPP
# define TYPES_HPP

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"

# include <iostream>
# include <list>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <stdexcept>
# include <vector>

typedef enum e_status
{
	WATER,
	SHIP,
	SHOOTED,
	SHOOTED_WATER	
}	t_status;

typedef enum e_orientation
{
	VERTICAL,
	HORIZONTAL
}	t_orientation;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

void	puterror(const char *s);

#endif
