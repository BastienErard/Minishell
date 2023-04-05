SOURCES	= 	$(wildcard *.c) \
			$(wildcard */*.c)
OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc -g3 -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -D_GNU_SOURCE
#RD_REPLACE = -L $(HOME)/.brew/Cellar/readline/8.2.1/lib -I $(HOME)/.brew/Cellar/readline/8.2.1/include
RD_REPLACE = -L /opt/homebrew/Cellar/readline/8.2.1/lib -I /opt/homebrew/Cellar/readline/8.2.1/include
RM		= rm -f

NAME	= minishell

all:	libft ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJECTS}
#		@${MAKE} -C libft all
		${CC} ${CFLAGS} -lreadline -o $@ $^ -L./libft -lft ${RD_REPLACE}

libft:
		make -C libft

clean:
		make clean -C libft
		${RM} ${OBJECTS}

fclean:		clean
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

.PHONY:	libft all bonus clean fclean re

