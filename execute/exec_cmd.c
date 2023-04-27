/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:48:46 by berard            #+#    #+#             */
/*   Updated: 2023/04/27 17:29:58 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Execute a command by first checking if it is a built-in or not.
 * If it is not, execute the external command in a child process.
*/
void	exec_cmd(t_token *token)
{
	if (is_builtins(token) == 1)
		exec_builtins(token);
	else
		exec_external_code(token);
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
