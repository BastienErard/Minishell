/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:08:12 by berard            #+#    #+#             */
/*   Updated: 2023/04/18 18:52:12 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * ECHO outputs text to the terminal. The -n option is used to prevent
 * the output from ending with a newline character.
 */
int	echo(t_token *token)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (token->arg[i] && ft_strcmp(token->arg[i], "-n") == 0)
	{
		flag = 1;
		i++;
	}
	while (token->arg[i])
	{
		ft_putstr_fd(token->arg[i], 1);
		if (token->arg[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
	return (EXIT_SUCCESS);
}
