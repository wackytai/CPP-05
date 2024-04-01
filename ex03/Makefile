NAME = intern
SOURCES = $(wildcard ./src/*.cpp)
CFLAGS = -Wall -Wextra -Wextra -g3 -std=c++98 -pedantic -fsanitize=address
CC = @c++

all:	$(NAME)
$(NAME):	$(SOURCES)
		$(CC) $(CFLAGS) $(^) -o $(@)

clean:
		@rm -f $(wildcard ./src/*.o)
		@rm -f ./*shrubbery

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re