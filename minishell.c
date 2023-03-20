/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:06 by berard            #+#    #+#             */
/*   Updated: 2023/03/20 11:06:08 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env) {
	char	*input;
	t_token	*head;

	(void)ac;
	(void)av;
	(void)env;

	// signals_init(); // TODO
	while (1)
	{
		input = readline("Minishell > ");
		head = tokenize(input);
		print_list(head);
		add_history(input);
	}
	free(input);
	return(0);
}
