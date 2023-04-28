/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:58 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/28 15:35:20 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* exec the commands when there is pipes in the input */
void	exec_cmds(t_token *token)
{
	int		fd_pipe_tmp;
	int		fd_pipe[2];
	int		exit_status;
	pid_t	fork_pid;

	fd_pipe_tmp = 0;
	while (token)
	{
		pipe(fd_pipe);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			prep_fd(token, &fd_pipe_tmp, fd_pipe);
			exec_cmd(token);
		}
		close_fd(token, &fd_pipe_tmp, fd_pipe);
		token = token->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	if (WIFEXITED(exit_status))
		g_exit_code = WEXITSTATUS(exit_status);
}

/* prapres the fd needed to execute the cmd */
void	prep_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe)
{
	close(fd_pipe[0]);
	if (token->fdread == 0)
		token->fdread = *fd_pipe_tmp;
	dup2(token->fdread, 0);
	if (token->fdwrite >= 3)
		close(fd_pipe[1]);
	else if (!token->next)
		token->fdwrite = 1;
	else
		token->fdwrite = fd_pipe[1];
	dup2(token->fdwrite, 1);
}

/* closes the fds that have been opened */
void	close_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe)
{
	close(fd_pipe[1]);
	if (*fd_pipe_tmp >= 3)
		close(*fd_pipe_tmp);
	if (token->fdwrite >= 3)
		close(token->fdwrite);
	if (token->fdread >= 3)
		close(token->fdread);
	*fd_pipe_tmp = fd_pipe[0];
}

// void	pipe_start(t_token *token)
// {
// 	// t_pipes	*pipes;
// 	// t_token *tmp;

// 	// tmp = token;
// 	(void)token;


// }

// void	parents(t_token *token, t_pipes *pipes)
// {
// 	pipes = malloc(sizeof(t_pipes));
// 	if (pipe(pipes->pfd) == -1)
// 		perror("issue with the pipes in parents()");
// 	pipes->pid = fork();
// 	if (pipes->pid < 0)
// 		perror("issue with the forking in parents()");
// 	if (pipes->pid == 0)
// 	{
// 		while (token)
// 		{
// 			child(token, pipes);
// 			token = token->next;
// 		}
// 	}
// 	else
// 	{
// 		close(pipes->pfd[0]);
// 		if (token->fdwrite == 0)
// 			dup2(pipes->pfd[1], 1);
// 		else
// 			dup2(token->fdwrite, 1);
// 		close(pipes->pfd[1]);
// 		close(token->fdwrite);
// 		exec_cmd(token);
// 	}
// 	free(pipes);
// }

// void	child(t_token *token, t_pipes *pipes)
// {
// 	close(pipes->pfd[1]);
// 	if (token->fdread == 0)
// 		dup2(pipes->pfd[0], 0);
// 	else
// 		dup2(token->fdread, 0);
// 	close(pipes->pfd[0]);
// 	close(token->fdread);
// 	exec_cmd(token);
// 	if (token->next)
// 		parents(token, pipes);
// }
