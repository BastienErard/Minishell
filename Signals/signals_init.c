/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:49:23 by tastybao          #+#    #+#             */
/*   Updated: 2023/03/31 14:20:23 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * This function sets up a signal handler for the SIGINT and SIGQUIT signals,
 * which will call the signals_handle function when those signals are received.
*/
void	signals_init(void)
{
	struct sigaction	sig;

	sig = (struct sigaction){0};
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGINT);
	sigaddset(&sig.sa_mask, SIGQUIT);
	sig.sa_handler = &signals_handle;
	if (sigaction(SIGINT, &sig, NULL) != 0)
		perror("Error with SIGINT");
	if (sigaction(SIGQUIT, &sig, NULL) != 0)
		perror("Error with SIGQUIT");
}
