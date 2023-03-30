/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:08:04 by berard            #+#    #+#             */
/*   Updated: 2023/03/30 09:53:16 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "env" command is used to display the current environment variables.
 * When the "env" command is run without any arguments, it displays a list of the
 * current environment variables and their values.
*/
void	ft_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (perror("env")); // Need to check, in case of unset's use.
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putstr_fd(env[i], 1);
		i++;
	}
}
