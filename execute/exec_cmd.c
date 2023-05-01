/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:48:46 by berard            #+#    #+#             */
/*   Updated: 2023/05/01 10:16:55 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Execute a command by first checking if it is a built-in or not.
 * If it is not, execute the external command in a child process.
*/
void	exec_cmd(t_token *token)
{
	int	init_stdout;
	int	init_stdin;

	init_stdout	= dup(STDOUT_FILENO);
	init_stdin = dup(STDIN_FILENO);
	if (token->fdread >= 3)
		dup2(token->fdread, STDIN_FILENO);
	if (token->fdwrite >= 3)
		dup2(token->fdwrite, STDOUT_FILENO);
	if (is_builtins(token) == 1)
		exec_builtins(token);
	else
		exec_external_code(token);
	if (token->fdread >= 3)
		close(token->fdread);
	if (token->fdwrite >= 3)
		close(token->fdwrite);
	dup2(init_stdout, STDOUT_FILENO);
	dup2(init_stdin, STDIN_FILENO);
	close(init_stdout);
	close(init_stdin);
}

/**
 * Execute the external command in a child process.
 * Use of WIFEXITED to retrieve the return code of execve or the function.
*/
void	exec_external_code(t_token *token)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		perror("Error with fork");
	if (pid == 0)
	{
		exec_external(token);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_code = WEXITSTATUS(status);
	}
}
