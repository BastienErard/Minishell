/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:37:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/22 13:42:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "grammar.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

// lexer.c

void	tokenize(t_token **head, char *input);
void	sequencer(t_token **head, char *input);
int		word_len(char *input, int i);
int		ft_isaspace(char c);

// linked_list.c

void	add_token(t_token **head, char **command);
void	add_last(t_token **head, t_token *new);
t_token	*get_last(t_token *head);
void	print_list(t_token *head);

//parser.c

void	parser(char	*input);

// Signals

void			signals_init(void);
void			signals_handle(int sig);

// Others

extern void 	rl_replace_line (const char *, int);
#endif
