/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:00:19 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/06 13:02:31 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns true if char is a redirection */
int	isredi(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

/* returns true if char is a delimiter
	if flag == s takes into account the spaces */
int	isdeli(char c, char flag)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	if (flag == 's' && ft_isaspace(c))
		return (1);
	return (0);
}

/* returns true if input is a space, false otherwise */
int	ft_isaspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

/* returns the index after it has eliminated the spaces */
void	space_index(t_token *new, char *input)
{
	while (input[new->i] && ft_isaspace(input[new->i]))
		new->i++;
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
