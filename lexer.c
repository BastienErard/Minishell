/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:14:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/23 18:04:02 by fgrasset         ###   ########.fr       */
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
		perror("The input is empty");
	while (input[i])
	{
		add_last(head, new);
	}
}

/* adds the cmd (first word) to the linked list */
void	get_cmd(t_token *new, char *input, int i)
{
	int		j;

	j = -1;
	if (input[i] == '\'' || input[i] == '"' && !check_quotes(input, input[i], i))
		perror("Issue with the quotes not ending");
	new->cmd = malloc(sizeof(char) * word_len(input, i));
	while (input[i] && !ft_isaspace(input[i]))
	{
		new->cmd[++j] = input[i];
		i++;
	}
	new->cmd[++j] = '\0';
	new->type = COMMAND;
	new->next = NULL;
}

/* adds the fdwrite or fdread depending on the redirection needed */
void	get_redirection(t_token *new, char *input,int i)
{

}

/* adds the arg going with the cmd to the linked list */
void	get_arg(t_token *new, char *input, int i)
{

}

/* returns true if there exist a quote to end it, false otherwise */
int	checkquotes(char *input, char quote, int i)
{
	while (input[++i])
	{
		if (input[i] == quote)
			return (1);
	}
	return (0);
}

/* returns true if char is a redirection */
int	isredi(char c)
{
	if (c == '<' || c == '>' || c == '<<' || c == '>>')
		return (1);
	return (0);
}

/* returns the index after it has eliminated the spaces */
int	ispace(char *input, int index)
{
	while (input[index] && ft_isaspace(input[index]))
		index++;
	return (index);
}

/* returns the length of the next word to be malloc*/
int	word_len(char *input, int i)
{
	int	len;

	len = 0;
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
