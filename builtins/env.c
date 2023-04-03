/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:08:04 by berard            #+#    #+#             */
/*   Updated: 2023/04/03 11:18:37 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "env" command is used to display the current environment variables.
 * When the "env" command is run without any arguments, it displays a list of the
 * current environment variables and their values.
*/
void	ft_env(t_token *token)
{
	if (!token->env)
		return (perror("env")); // Need to check, in case of unset's use.
	while (token->env)
	{
		ft_putstr_fd(token->env->var[0], 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(token->env->var[1], 1);
		ft_putstr_fd("\n", 1);
		token->env = token->env->next;
	}
}
