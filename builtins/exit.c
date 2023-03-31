/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:31:13 by berard            #+#    #+#             */
/*   Updated: 2023/03/31 09:08:25 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "exit" command s used to exit the current shell
 * and signal the exit status of the process to the operating system.
*/
void	ft_exit(t_token *token)
{
	token->cmd = NULL; // To changes
	ft_putstr_fd("exit\n", 1);
	// free_linked_list(token); // TODO - FGRASSET
	rl_clear_history();
	exit (0); // Quid des fichiers open? Doivent être fermés.
}
