SOURCES	= $(wildcard *.c)
OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc -g3 -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAME	= minishell

all:	${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJECTS}
		@${MAKE} -C libft all
		${CC} ${CFLAGS} -lreadline -o $@ $^ -L./libft -lft

libft:
		make -C libft

clean:
		make clean -C libft
		${RM} ${OBJECTS}

fclean:		clean
		make fclean -C libft
		${RM} ${NAME}

re:
		fclean all

.PHONY:	libft all bonus clean fclean re

