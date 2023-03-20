/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:49:23 by tastybao          #+#    #+#             */
/*   Updated: 2023/03/20 10:46:29 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    signals_init(void)
{
    struct sigaction    signal;

    signal = (struct sigaction){0};
    sigemptyset(&signal.sa_mask);
    sigaddset(&signal.sa_mask, SIGINT);
    signal.sa_handler = &signals_handle;
    if (sigaction(SIGINT, &signal, NULL) != 0)
        perror("Error with SIGINT");
}
