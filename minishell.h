/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:37:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/15 13:08:25 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "grammar.h"
# include <readline/readline.h>
# include <readline/history.h>

// lexer.c

t_token	*tokenize(char *input);
char	*sequencer(char *input);
int	ft_isaspace(char c);


// linked_list.c

void	add_token(t_token **head, char **command);
t_token	*get_last(t_token *head);
void	print_list(t_token *head);

#endif
