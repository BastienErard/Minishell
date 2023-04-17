/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:08:04 by berard            #+#    #+#             */
/*   Updated: 2023/04/17 16:11:44 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "env" command is used to display the current environment variables.
 * When the "env" command is run without any arguments, it displays a list of the
 * current environment variables and their values.
*/
int	ft_env(t_token *token)
{
	if (!token->env || pathless(token->env) == 0)
	{
		ft_putstr_fd("env: No such file or directory\n", 2);
		return (127);
	}
	if (token->arg[0] && ft_strcmp(token->arg[0], "test") == 0)
		return (EXIT_FAILURE);
	if (token->arg[0])
		return (env_with_arg(token->arg[0]));
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

int	env_with_arg(char *str)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (127);
}

int	pathless(t_env *env)
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
