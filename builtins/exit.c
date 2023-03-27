/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:31:13 by berard            #+#    #+#             */
/*   Updated: 2023/03/27 14:06:26 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "exit" command in Bash is used to exit the current shell
 * and signal the exit status of the process to the operating system.
*/
void	ft_exit(t_token *token)
{
	ft_putstr_fd("exit\n", 1);
	// free_linked_list(token); // TODO - FGRASSET
	exit (0); // Quid des fichiers open? Doivent être fermés.
}
