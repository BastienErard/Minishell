/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:14:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/20 14:56:06 by fgrasset         ###   ########.fr       */
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
t_token	*tokenize(char *input)
{
	static t_token	*head;
	static char		**cmd;
	int			i;

	i = 0;
	cmd = malloc(sizeof(char*) * 10);
	cmd[i] = sequencer(input);
	while(cmd[i])
	{
		i++;
		cmd[i] = sequencer(input);
	}
	add_token(&head, cmd);
	free(cmd);
	return (head);
}

/* returns a string that contains what's between the good delimiters */
char	*sequencer(char *input)
{
	static int	i;
	int			j;
	static char	*cmd;

	j = 0;
	cmd	= malloc(sizeof(char) * 100);
	if (input[i] == '\0')
		return  (NULL);
	while (input[i] && ft_isaspace(input[i]))
		i++;
	while (input[i] && !ft_isaspace(input[i]))
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
