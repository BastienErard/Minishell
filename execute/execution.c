/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:22:25 by berard            #+#    #+#             */
/*   Updated: 2023/03/24 16:43:28 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_token *token)
{
	if (!token->next)
		exec_cmd(token); // TODO
	// else
	// 	exec_cmds(token); // TODO
}
