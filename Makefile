CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude
SRCS = $(wildcard src/*.cpp) $(wildcard src/class/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = battleship

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXECUTABLE)

.PHONY: all re clean fclean