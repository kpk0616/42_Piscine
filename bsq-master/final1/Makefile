SRC			= main.c hub.c parse.c create_matrice.c ft_list_push_back.c ft_create_elem.c clear.c ft_putall.c matrice.c check.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

NAME		= bsq

RM			= rm -f

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
