CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = $(wildcard src/*.cpp) $(wildcard src/class/*.cpp)
OBJS = $(SRCS:.cpp=.o)

EXECUTABLE = battleship

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re