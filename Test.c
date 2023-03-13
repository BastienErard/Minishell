/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:06 by berard            #+#    #+#             */
/*   Updated: 2023/03/13 13:18:31 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env) {
	char	*input;
	// printf("Enter a line of text:\n");
	// input = readline("Minishell > ");
	// printf("you entered: %s\n", input);
	while (1)
	{
		input = readline("Minishell > ");
		printf("This is the input: %s\n", input);
		add_history(input);
	}
	free(input);
	return(0);
}
