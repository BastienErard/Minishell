/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:14:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/13 20:18:47 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Assign the tokens to the given input
 *
 * @param [input] input from the readline
 *
 * @return returns the linked list containing
 * the tokenized input
 */
t_token	tokenize(char *input)
{
	t_token	head;



	return (head);
}

/* returns a string containes between the good delimiters */
char	*sequencer(char *input)
{
	int		i;
	int		j;
	char	*cmd;

	i = 0;
	j = 0;
	while (ft_isaspace(input[i]))
		i++;
	while (!isaspace(input[i]))
	{
		cmd[j] = input[i];
		i++;
		j++;
	}
	cmd[i] = '\0';
	return (cmd);
}

/* returns true if input is a space, false otherwise */
int	ft_isaspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
