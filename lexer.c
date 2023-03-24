/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:14:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/24 16:20:24 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* cut the input in words and add them to the linked list */
void	sequencer(t_token **head, char *input)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	new->i = 0;
	if (input[new->i] == '\0')
		perror("The input is empty");
	while (input[new->i])
	{
		space_index(new, input);
		while (input[new->i] != '|')
		{
			get_cmd(new, input);
			if (isredi(input[new->i]))
				get_redirection(new, input);
			else
				get_arg(new, input);
		}
		add_last(head, new);
	}
}

/* adds the cmd (first word) to the linked list */
void	get_cmd(t_token *new, char *input)
{
	int		j;

	j = -1;
	if ((input[new->i] == '\'' || input[new->i] == '"') && !checkquotes(input, input[new->i], new->i))
		perror("Issue with the quotes not ending");
	new->cmd = malloc(sizeof(char) * word_len(input, new->i));
	while (input[new->i] && !ft_isaspace(input[new->i]))
	{
		new->cmd[++j] = input[new->i];
		new->i++;
	}
	new->cmd[++j] = '\0';
	new->type = COMMAND;
	new->next = NULL;
	space_index(new, input);
}

/* adds the fdwrite or fdread depending on the redirection needed to the token */
void	get_redirection(t_token *new, char *input)
{
	if (input[new->i] == '<')
	{

	}
	else if (input[new->i] == '>')
	{

	}
}

/* adds the arg going with the cmd to token */
void	get_arg(t_token *new, char *input)
{
	int	pos;

	pos = 0;
	new->arg = malloc(sizeof(char) * 100);		//make a function later to count the number of words
	if (!new->arg)
		perror("issue malloc get_arg");
	while (input[new->i] && !isredi(input[new->i]) && input[new->i] != '|')
	{
		space_index(new, input);
		if ((input[new->i] == '\'' || input[new->i] == '"') && !checkquotes(input, input[new->i], new->i))
			perror("Issue with the quotes not ending");
		get_word(new, input, pos);
		new->i++;
	}
}

/* returns the length of the next word to be malloc*/
int	word_len(char *input, int i)
{
	int	len;

	len = 0;
	while (input[i] && !isdeli(input[i], '!'))
	{
		len++;
		i++;
	}
	return (len + 1);
}
