/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:23:24 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/24 16:17:04 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

/* adds the characters until space or delimiters
and adds it in the token->arg at arg[pos], with a malloc */
void	get_word(t_token *new, char *input, int pos)
{
	int	j;

	j = -1;
	new->arg[pos] = malloc(sizeof(char) * word_len(input, new->i));
	if (!new->arg[pos])
		perror("issue malloc get_word");
	while (input[new->i] && !isdeli(input[new->i], 's'))
	{
		new->arg[pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[pos][++j] = '\0';
}
/* adds what is between the single quotes to the arg at pos */
void	get_squote(t_token *new, char *input, int pos)
{
	int	j;

	j = -1;
	if (!checkquotes(input, input[new->i], new->i))
		perror("Issue with the singe quote not ending");
	new->arg[pos] = malloc(sizeof(char) * mystrcspn(input, "\'", new->i));
	if (!new->arg[pos])
		perror("Issue malloc get_squote");
	while (input[new->i] && input[new->i] != '\'')
	{
		new->arg[pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[pos][++j] = '\0';
}

/* adds what is between double quotes to arg and if $env
	adds it to pos + 1 and adds rest of string to pos + 2*/
void	get_dquote(t_token *new, char *input, int pos)
{
	int	j;

	j = -1;
	if (!checkquotes(input, input[new->i], new->i))
		perror("Issue with the double quotes not ending");
	new->arg[pos] = malloc(sizeof(char) * mystrcspn(input, "\"$", new->i));
	if (!new->arg[pos])
		perror("Issue malloc get_dquote");
	while (input[new->i] && input[new->i] != '"' && input[new->i] != '$')
	{
		if (input[new->i] == '$')
		{
			new->arg[pos][++j] = '\0';
			j = -1;
			new->flag_env = 1;
			new->arg[++pos] = malloc(sizeof(char) * mystrcspn(input, " \t", new->i));
			while (input[new->i] && !ft_isaspace(input[new->i]))
			{
				new->arg[pos][++j] = input[new->i];
				new->i++;
			}
			new->arg[pos][++j] = '\0';
			new->arg[++pos] = malloc(sizeof(char) * mystrcspn(input, "\"$", new->i));

		}
		else
		{
			new->arg[pos][++j] = input[new->i];
			new->i++;
		}
	}
	new->arg[pos][++j] = '\0';
}

/**
Returns the length of the initial segment of the string 's' that
contains no characters from the string 'reject'.
@param s Pointer to the string to search for characters not in 'reject'.
@param reject Pointer to the string containing characters to reject.
@return The length of the initial segment of 's' containing no characters from 'reject'.
This function iterates over the characters in the string 's' until it finds
a character that is also present in the string 'reject'.
At that point, it returns the index of that character in the string 's', which
represents the length of the initial segment of 's'
containing no characters from 'reject'.
If no characters in 's' are found to be in 'reject',
the function returns the length of 's'.
Example usage:
char *s = "hello";
char *reject = "ol";
int len = ft_strcspn(s, reject); // len == 2
*/
int	mystrcspn(char *s, char *reject, int i)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[i] != '\0')
		{
			if(s[i] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}
