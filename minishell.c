
#include "minishell.h"

int	g_exit_code = 0;

int	main(int ac, char **av, char **env)
{
	struct termios	termios;
	t_env			*envi;
	char			*input;

	(void)ac;
	(void)av;
	envi = malloc(sizeof(t_env));
	ft_memset(envi, 0, sizeof(t_env));
	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
	input = "start";
	init_env(&envi, env);
	signals_init();
	while (input != NULL)
	{
		input = readline("\e[1;36mMinishell > \e[0m");
		if ((input && input[0] == '\0') || input == NULL)
			continue ;
		parser(input, envi);
		add_history(input);
	}
	free(input);
	free_env(&envi);
	return (0);
}
