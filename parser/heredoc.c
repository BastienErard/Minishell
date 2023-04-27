/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:34:25 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/27 15:06:16 by fabien           ###   ########.fr       */
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
	while (ft_strcmp(here, new->end_of_file))
	{
		write(heredoc, here, ft_strlen(here));
		write(heredoc, "\n", 1);
		free(here);
		here = readline("");
	}
	free(here);
	//TODO executes what is inside the heredoc file
	close(heredoc);
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
