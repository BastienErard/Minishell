/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:48:46 by berard            #+#    #+#             */
/*   Updated: 2023/03/31 14:44:45 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Execute a command by first checking if it is a built-in or not.
 * If it is not, execute the external command in a child process.
*/
void	exec_cmd(t_token *token)
{
	pid_t	pid;

	if (is_builtins(token) == 1)
		exec_builtins(token);
	else
	{
		pid = fork();
		if (pid == -1)
			return (perror("Error with fork"));
		if (pid == 0)
		{
			exec_external(token);
			exit (0);
		}
		waitpid(pid, NULL, 0);
	}
}
