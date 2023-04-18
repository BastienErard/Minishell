/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:08:04 by berard            #+#    #+#             */
/*   Updated: 2023/04/18 18:56:45 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Display the current environment variables.
 * When the command is run without any arguments, it displays a list of the
 * current environment variables and their values.
*/
int	ft_env(t_token *token)
{
	if (!token->env || env_pathless(token->env) == 0)
	{
		ft_putstr_fd("env: No such file or directory\n", 2);
		return (127);
	}
	if (token->arg[0] && ft_strcmp(token->arg[0], "test") == 0)
		return (EXIT_FAILURE);
	if (token->arg[0])
		return (env_error(token->arg[0]));
	while (token->env)
	{
		if (token->env->var[1])
		{
			ft_putstr_fd(token->env->var[0], 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(token->env->var[1], 1);
			ft_putstr_fd("\n", 1);
		}
		token->env = token->env->next;
	}
	return (EXIT_SUCCESS);
}

/* Prints an error message when the path or file is wrong. */
int	env_error(char *str)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (127);
}

/* Checks for the presence of PATH in the environment. */
int	env_pathless(t_env *env)
{
	int	flag;

	flag = 0;
	while (env && env->var[1])
	{
		if (ft_strcmp(env->var[0], "PATH") == 0)
		{
			flag = 1;
			break ;
		}
		env = env->next;
	}
	return (flag);
}
