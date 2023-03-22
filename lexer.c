/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:14:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/22 14:15:00 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Assign the tokens to the given input
 *
 * @param [input] input from the readline
 *
 * @return returns nothing but executes the needed commands
 */
// void	tokenize(t_token **head, char *input)
// {

// }

/* cut the input in words and add them to the linked list */
void	sequencer(t_token **head, char *input)
{
	int		i;
	int		j;
	t_token	*new;

	i = 0;
	if (input[i] == '\0')
		return ;
	while (input[i])
	{
		new = malloc(sizeof(t_token));
		j = -1;
		new->str = malloc(sizeof(char) * word_len(input, i));
		new->len = word_len(input, i);
		while (input[i] && ft_isaspace(input[i]))
			i++;
		while (input[i] && !ft_isaspace(input[i]))
		{
			new->str[++j] = input[i];
			i++;
		}
		new->str[++j] = '\0';
		new->next = NULL;
		add_last(head, new);
	}
}

/* returns the length of the next word to be malloc*/
int	word_len(char *input, int i)
{
	int	len;

	len = 0;
	while (input[i] && ft_isaspace(input[i]))
		i++;
	while (input[i] && !ft_isaspace(input[i]))
	{
		len++;
		i++;
	}
	return (len + 1);
}

/* returns true if input is a space, false otherwise */
int	ft_isaspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
