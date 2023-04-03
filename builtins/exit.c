/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:31:13 by berard            #+#    #+#             */
/*   Updated: 2023/04/03 15:03:18 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * The "exit" command s used to exit the current shell
 * and signal the exit status of the process to the operating system.
*/
void	ft_exit(t_token *token)
{
	ft_putstr_fd("exit\n", 1);
	free_token(&token);
	free_env(&token->env);
	rl_clear_history();
	exit (0); // Quid des fichiers open? Doivent être fermés.
}
