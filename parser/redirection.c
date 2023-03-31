/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:57:42 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/31 14:48:41 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* opens the file in fdread and put the good value in file_type */
void	r_left(t_token	*new, char *input)
{
	char	*file;

	file = get_file(new, input);
	new->fdread = open(file, O_RDONLY);
	if (!new->fdread)
	{
		perror("issue open r_left");
		return ;
	}
	new->file_type = R_LEFT;
}

/* opens the file in fdread and put the good value in file_type */
void	rr_left(t_token	*new, char *input)
{
	char	*file;

	new->i++;
	file = get_file(new, input);
	new->fdread = open(file, O_RDONLY);
	if (!new->fdread)
	{
		perror("issue open r_left");
		return ;
	}
	new->file_type = RR_LEFT;
	//TODO
}

/* opens the file in fdwrite and put the good value in file_type */
void	r_right(t_token	*new, char *input)
{
	char	*file;

	file = get_file(new, input);
	new->fdread = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (!new->fdread)
	{
		perror("issue open r_left");
		return ;
	}
	new->file_type = R_RIGHT;
}

/* opens the file in fdwrite and put the good value in file_type */
void	rr_right(t_token	*new, char *input)
{
	char	*file;

	new->i++;
	file = get_file(new, input);
	new->fdread = open(file, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (!new->fdread)
	{
		perror("issue open r_left");
		return ;
	}
	new->file_type = RR_RIGHT;
}

/* returns the string after the redirection, containing the PATH */
char	*get_file(t_token *new, char *input)
{
	int		j;
	char	*file;

	j = -1;
	file = malloc(sizeof(char) * word_len(input, new->i));
	if (!file)
		perror("issue malloc get_file");
	while (input[new->i] && !ft_isaspace(input[new->i]))
	{
		file[++j] = input[new->i];
		new->i++;
	}
	file[++j] = '\0';
	return (file);
}
