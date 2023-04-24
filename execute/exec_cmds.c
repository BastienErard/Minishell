/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:58 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/24 14:26:35 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* exec the commands when there is pipes in the input */
void	exec_cmds(t_token *token)
{
	pipe_start(token);
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

void	pipe_start(t_token *token)
{
	// t_pipes	*pipes;
	// t_token *tmp;

	// tmp = token;
	(void)token;


}

void	parents(t_token *token, t_pipes *pipes)
{
	pipes = malloc(sizeof(t_pipes));
	if (pipe(pipes->pfd) == -1)
		perror("issue with the pipes in parents()");
	pipes->pid = fork();
	if (pipes->pid < 0)
		perror("issue with the forking in parents()");
	if (pipes->pid == 0)
	{
		while (token)
		{
			child(token, pipes);
			token = token->next;
		}
	}
	else
	{
		close(pipes->pfd[0]);
		if (token->fdwrite == 0)
			dup2(pipes->pfd[1], 1);
		else
			dup2(token->fdwrite, 1);
		close(pipes->pfd[1]);
		close(token->fdwrite);
		exec_cmd(token);
	}
	free(pipes);
}

void	child(t_token *token, t_pipes *pipes)
{
	close(pipes->pfd[1]);
	if (token->fdread == 0)
		dup2(pipes->pfd[0], 0);
	else
		dup2(token->fdread, 0);
	close(pipes->pfd[0]);
	close(token->fdread);
	exec_cmd(token);
	if (token->next)
		parents(token, pipes);
}
