/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:44 by berard            #+#    #+#             */
/*   Updated: 2023/04/13 10:20:11 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * CD is used in command line to change the current working directory
 * of the shell or program to a specified directory.
*/
int	cd(t_token *token)
{
	if (!token->arg[0] || ft_strcmp(token->arg[0], "~") == 0)
	{
		while (token->env)
		{
			if (ft_strcmp(token->env->var[0], "HOME") == 0)
				break ;
			if (!token->env->next)
			{
				ft_putstr_fd("cd: HOME not set\n", 2);
				return (EXIT_FAILURE);
			}
			token->env = token->env->next;
		}
		if (chdir(token->env->var[1]) != 0)
			return (chdir_failed(token));
	}
	else
	{
		if (chdir(token->arg[0]) != 0)
			return (chdir_failed(token));
	}
	return (EXIT_SUCCESS);
}

int	chdir_failed(t_token *token)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(token->arg[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (EXIT_FAILURE);
}
