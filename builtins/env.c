/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:08:04 by berard            #+#    #+#             */
/*   Updated: 2023/04/05 19:49:42 by fabien           ###   ########.fr       */
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
	// t_env	*tmp;

	if (!token->env)
	{
		perror("env"); // Need to check, in case of unset's use.
		return (errno);
	}
	// tmp = token->env;
	// while (tmp)
	// {
	// 	if (ft_strcmp(tmp->var[0], "PATH") == 0)
	// 	{
	// 		ft_putstr_fd("env: No such file or directory\n", 2);
	// 		return (127);
	// 	}
	// 	tmp = tmp->next;
	// }
	while (token->env && token->env->var[1])
	{
		ft_putstr_fd(token->env->var[0], 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(token->env->var[1], 1);
		ft_putstr_fd("\n", 1);
		token->env = token->env->next;
	}
	return (EXIT_SUCCESS);
}
