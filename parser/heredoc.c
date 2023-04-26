/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:34:25 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/26 15:53:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* creates the heredoc and executes it */
void	heredoc(t_token *new, char *input)
{
	char	*here;

	(void)input;
	here = readline("");
	while (ft_strcmp(here, new->end_of_file))
	{
		write(new->fdwrite, here, ft_strlen(here));
		write(new->fdwrite, "\n", 1);
		free(here);
		here = readline("");
	}

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
