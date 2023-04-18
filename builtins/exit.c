/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:31:13 by berard            #+#    #+#             */
/*   Updated: 2023/04/18 18:58:28 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Exit the current shell and signal the exit status of
 * the process to the operating system.
*/
void	ft_exit(t_token *token)
{
	ft_putstr_fd("exit\n", 1);
	free_env(&token->env);
	free_token(&token);
	rl_clear_history();
	exit (0); // Quid des fichiers open? Doivent être fermés.
}
