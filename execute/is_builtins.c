/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:44:33 by berard            #+#    #+#             */
/*   Updated: 2023/03/31 09:20:57 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtins(t_token *token)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(token->cmd, "echo") == 0
		|| ft_strcmp(token->cmd, "pwd") == 0
		|| ft_strcmp(token->cmd, "exit") == 0
		|| ft_strcmp(token->cmd, "cd") == 0
		|| ft_strcmp(token->cmd, "env") == 0
		|| ft_strcmp(token->cmd, "unset") == 0
		|| ft_strcmp(token->cmd, "export") == 0)
		flag = 1;
	return (flag);
}
