/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:41:03 by berard            #+#    #+#             */
/*   Updated: 2023/04/13 10:38:16 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * This function manages the shell's functions and, if it finds nothing,
 * indicates that the command does not exist.
*/
void	exec_external(t_token *token)
{
	char	**path;
	char	filepath[MAXPATHLEN];
	int		i;

	i = -1;
	if (access(token->cmd, X_OK) == 0)
		execve(token->cmd, token->arg, get_env(token));
	path = ft_split(getenv("PATH"), ':'); // TODO - Getenv is not optimal
	if (!path)
		return (perror("Error with split during execution of an external"));
	while (path[++i])
	{
		ft_strlcpy(filepath, path[i], sizeof(filepath));
		ft_strlcat(filepath, "/", sizeof(filepath));
		ft_strlcat(filepath, token->cmd, sizeof(filepath));
		if (access(filepath, X_OK) == 0)
		{
			free_split(path);
			execve(filepath, token->arg, get_env(token)); // ISSUE LS
		}
	}
	free_split(path);
	ft_putstr_fd(token->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}

char	**get_env(t_token *token)
{
	t_token	*tmp;
	char	**genv;
	int		i;

	i = 0;
	tmp = token;
	while (tmp->env)
	{
		i++;
		tmp->env = tmp->env->next;
	}
	genv = malloc(sizeof(char) * i);
	tmp = token;
	i = -1;
	while (tmp->env)
	{
		genv[++i] = malloc(sizeof(char) * (ft_strlen(tmp->env->var[0]) + ft_strlen(tmp->env->var[1]) + 1));
		fuckit(genv[i], tmp->env->var[0], tmp->env->var[1]);
		tmp->env = tmp->env->next;
	}
	genv[++i] = NULL;
	return (genv);
}

/* it just fucking does it */
void	fuckit(char *genv, char *var1, char *var2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (var1[++j])
	{
		genv[++i] = var1[j];
	}
	genv[++i] = '=';
	j = -1;
	while (var2[++j])
	{
		genv[++i] = var2[j];
	}
	genv[++i] = '\0';
}
