/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:37:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/22 17:40:46 by berard           ###   ########.fr       */
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

t_token	*tokenize(char *input);
char	*sequencer(char *input);
int		ft_isaspace(char c);

// linked_list.c

void	add_token(t_token **head, char **command);
t_token	*get_last(t_token *head);
void	print_list(t_token *head);

// Signals

void			signals_init(void);
void			signals_handle(int sig);

// Others

extern void 	rl_replace_line (const char *, int);
#endif
