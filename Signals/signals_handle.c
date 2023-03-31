/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:58:40 by tastybao          #+#    #+#             */
/*   Updated: 2023/03/31 09:08:19 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signals_handle(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 128 + SIGINT;
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 128 + SIGQUIT;
	}
}
