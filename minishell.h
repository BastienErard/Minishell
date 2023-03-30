/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:37:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/30 17:51:24 by berard           ###   ########.fr       */
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
# include <sys/param.h>

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
int				is_builtins(t_token *token);
void			exec_cmd(t_token *token); // TODO
void			exec_cmds(t_token *token); // TODO
void			exec_external(t_token *token); // TO CHECK
void			exec_builtins(t_token *token); // TO ADAPT

// Builtins

void			echo(t_token *token); // TO CHECK
void			pwd(void); // TO CHECK
void			ft_exit(t_token *token); // TO COMPLETE
void			ft_env(char **env); // TO CHECK
void			cd(t_token *token); // TO COMPLETE (tilde)
// void			unset(t_token *token, char **env); // TODO

// Builtins  - Annex

void			chdir_failed(t_token *token);
// void			dir_backward(char *init_dir, t_token *token);
// void			dir_further(char *init_dir, t_token *token);

// Utils

// int				ft_strcmp(const char *s1, const char *s2); // TO CHECK / UNUSED FOR THE MOMENT
char			*ft_strncpy(char *dest, char *src, unsigned int n); // TO CHECK

// Free

void			free_split(char *path[]); // TO CHECK

// Others

extern void 	rl_replace_line (const char *, int);
extern void		rl_clear_history(void);
#endif
