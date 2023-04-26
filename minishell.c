
#include "minishell.h"

int	g_exit_code = 0;

int	main(int ac, char **av, char **env)
{
	t_env			*envi;
	char			*input;

	(void)ac;
	(void)av;
	envi = malloc(sizeof(t_env));
	ft_memset(envi, 0, sizeof(t_env));
	init_termios();
	input = "start";
	init_env(&envi, env);
	while (input != NULL)
	{
		signals_init();
		input = readline("\e[1;36mMinishell > \e[0m");
		if (((input && input[0] == '\0') || input == NULL) || space(input) == 0)
			continue ;
		parser(input, envi);
		add_history(input);
	}
	free(input);
	free_env(&envi);
	return (0);
}
