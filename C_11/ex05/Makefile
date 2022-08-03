CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)

NAME = do-op

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
