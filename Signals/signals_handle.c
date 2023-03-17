/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:58:40 by tastybao          #+#    #+#             */
/*   Updated: 2023/03/17 09:11:06 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    signals_handle(int sig)
{
    if (sig == SIGINT)
    {  
        printf("\n");
        // rl_replace_line("\n", 0);
        rl_redisplay();
    }
}