/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:06 by berard            #+#    #+#             */
/*   Updated: 2023/03/27 14:51:30 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char			*input;
	struct termios	termios;

	(void)ac;
	(void)av;
	(void)env;
	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
	input = "lol";
	while (input != NULL)
	{
		signals_init();
		input = readline("Minishell > ");
		parser(input);
		add_history(input);
	}
	free(input);
	return (0);
}
