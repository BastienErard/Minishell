/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:34:25 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/28 15:14:27 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* creates the heredoc and executes it */
void	heredoc(t_token *new, char *input)
{
	char	*here;
	int		heredoc;

	(void)input;
	heredoc = open("heredoc.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (!heredoc)
	{
		perror("error creating heredoc file");
		return ;
	}
	here = readline("");
	while (!iscontained(here, new->end_of_file))
	{
		write(heredoc, here, ft_strlen(here));
		write(heredoc, "\n", 1);
		free(here);
		here = readline("");
	}
	free(here);
	new->fdread = heredoc;
	//TODO executes what is inside the heredoc file
	// close(heredoc);
}

/* returns true if EOF is contained in the string */
int	iscontained(char *here, char *eof)
{
	int	i;

	i = -1;
	while (here[++i])
	{
		if (isword(here, eof, i))
			return 1;
	}
	return 0;
}

/* returns true if the word is found */
int	isword(char *here, char *eof, int index)
{
	while (eof[index])
	{
		if (eof[index] == here[index])
			index++;
		else
			return 0;
	}
	return 1;
}


// /* returns the file in which to execute heredoc if there is one
//  returns NULL otherwise */
// char *heredoc_file(t_token *new, char *input)
// {
// 	space_index(new, input);
// 	if (!input[new->i])
// 		return (NULL);
// 	if ((input[new->i] != '<') && (input[new->i] != '>'))
// 		return (NULL);
// }
