/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:41:03 by berard            #+#    #+#             */
/*   Updated: 2023/03/24 16:33:31 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_external(t_token *token)
{
	char	**path;
	char	filepath[1080];
	int		i;

	i = -1;
	if (access(token->cmd, X_OK) == 0)
		execve(token->cmd, token->arg, NULL); // WARNING - Maybe token->arg must contain ls
	path = ft_split(getenv("PATH"), ':'); // TODO - Getenv is not optimal
	if (!path)
		return (perror("Error with split during execution of an external"));
	while (path[++i])
	{
		ft_strlcpy(filepath, path[i], 1080);
		ft_strlcat(filepath, "/", 1080);
		ft_strlcat(filepath, token->cmd, 1080);
		if (access(filepath, X_OK) == 0)
		{
			free_split(path);
			execve(filepath, token->arg, NULL);
		}
	}
	free_split(path);
	ft_putstr_fd(token->cmd, 2);
	ft_putstr_fd("Command not found\n", 2);
}
