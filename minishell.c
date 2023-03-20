/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:06 by berard            #+#    #+#             */
/*   Updated: 2023/03/20 15:03:32 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char	*input;
	// t_token	*head;

	(void)ac;
	(void)av;
	(void)env;
	input = "lol";

	signals_init(); // TODO
	while (input != NULL)
	{
		input = readline("Minishell > ");
		// head = tokenize(input);
		// print_list(head);
		add_history(input);
	}
	free(input);
	return(0);
}
