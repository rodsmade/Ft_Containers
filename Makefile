NAME = containers_test.out

CC = c++ -Wall -Wextra -Werror

SOURCES = ft_map.cpp ft_set.cpp ft_stack.cpp ft_vector.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(NAME)

%.o:	%.cpp %.hpp
	$(CC) $(CFLAGS) $< -c -o $@

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind