/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:58 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/12 13:44:06 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* exec the commands when there is pipes in the input */
void	exec_cmds(t_token *token)
{
	parents(token);
	// while (current)
	// {
	// 	if (pipe(pfd) ==  -1)
	// 		return ;
	// 	if ((pid = fork()) < 0)
	// 		return ;

	// 	if (pid == 0)
	// 	{
	// 		/*child*/
	// 		close(pfd[1]);
	// 		dup2(pfd[0], 0);
	// 		close(pfd[0]);
	// 		exec_cmd(second);

	// 	}
	// 	else
	// 	{
	// 		/*parent*/
	// 		close(pfd[0]);
	// 		dup2(pfd[1], 1);
	// 		close(pfd[1]);
	// 		exec_cmd(first);
	// 	}
	// }
}

void	parents(t_token *token)
{
	t_pipes	*pipes;

	pipes = malloc(sizeof(t_pipes));
	// pipes->current = token;
	pipe(pipes->pfd);
	pipes->pid = fork();
	if (pipes->pid == 0)
	{
		if (token->next)
			parents(token->next);
		child(token, pipes);
	}
	else
	{
		close(pipes->pfd[0]);
		dup2(pipes->pfd[1], 1);
		close(pipes->pfd[1]);
		exec_cmd(token);
	}
}

void	child(t_token *token, t_pipes *pipes)
{
	close(pipes->pfd[1]);
	dup2(pipes->pfd[0], 0);
	close(pipes->pfd[0]);
	exec_cmd(token);
}
