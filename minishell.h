/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:37:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/27 16:01:34 by berard           ###   ########.fr       */
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

void			sequencer(t_token **head, char *input);
void			get_cmd(t_token *new, char *input);
void			get_redirection(t_token *new, char *input);
void			get_arg(t_token *new, char *input);
int				word_len(char *input, int i);

// lexer_utils.c

int				isredi(char c);
int				isdeli(char c, char flag);
int				ft_isaspace(char c);
void			space_index(t_token *new, char *input);
int				checkquotes(char *input, char quote, int i);

// linked_list.c

void			add_token(t_token **head, char **command);
void			add_last(t_token **head, t_token *new);
t_token			*get_last(t_token *head);
void			print_list(t_token *head);

// get.c
void			get_word(t_token *new, char *input, int pos);
void			get_squote(t_token *new, char *input, int pos);
void			get_dquote(t_token *new, char *input, int pos);
int				mystrcspn(char *s, char *reject, int i);

//parser.c

void			parser(char	*input);

// Signals

void			signals_init(void);
void			signals_handle(int sig);

// Execution

void			execution(t_token *token);
void			exec_cmd(t_token *token); // TO DO
void			exec_cmds(t_token *token); // TO DO
void			exec_external(t_token *token); // TO CHECK

// Builtins

void			echo(t_token *token); // TO CHECK
void			pwd(void); // TO CHECK
void			ft_exit(t_token *token); // TO COMPLETE
void			ft_env(char **env); // TO CHECK
void			cd(t_token *token);
void			unset(t_token *token, char **env); // TODO

// Utils

int				ft_strcmp(const char *s1, const char *s2);

// Free

void			free_split(char *path[]);

// Others

extern void 	rl_replace_line (const char *, int);
#endif
