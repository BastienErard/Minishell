
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "grammar.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <sys/param.h>
# include <errno.h>

// Global

extern int		g_exit_code;

// lexer.c

int				sequencer(t_token **head, char *input, t_env *envi, int index);
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
void			initialisation(t_token	*head);

// linked_list.c

void			add_token(t_token **head, char **command);
void			add_last(t_token **head, t_token *new);
t_token			*get_last(t_token *head);
void			print_list(t_token *head);

// get.c

void			get_word(t_token *new, char *input);
void			get_squote(t_token *new, char *input);
void			get_dquote(t_token *new, char *input);
int				mystrcspn(char *s, char *reject, int i);
int				env_handler(t_token *new, char *input, int j);


// redirection.c

void			r_left(t_token *new, char *input);
void			rr_left(t_token *new, char *input);	//TODO not finished
void			r_right(t_token *new, char *input);
void			rr_right(t_token *new, char *input);
char			*get_file(t_token *new, char *input);

//parser.c

void			parser(char *input, t_env *envi);
void			init_env(t_env **envi, char **env);
void			add_env(t_env **envi, char *env);
void			az_env(t_token *token);
void			env_init(t_token *token);


// Signals

void			signals_init(void); // TO CHECK
void			signals_handle(int sig); // TO CHECK

// Execution

void			execution(t_token *token); // TO COMPLETE
int				is_builtins(t_token *token); // TO CHECK
void			replace_usd(t_token *token); // TO CHECK
void			exec_cmd(t_token *token); // TO COMPLETE
void			exec_cmds(t_token *token); // TO CREATE
void			exec_external(t_token *token); // TO CHECK
int				exec_builtins(t_token *token); // TO ADAPT && COMPLETE
char			**get_env(t_token *token);
void			fuckit(char *genv, char *var1, char *var2);


// Builtins

int				echo(t_token *token); // TO CHECK
int				pwd(void); // TO CHECK
void			ft_exit(t_token *token); // TO COMPLETE (FREE)
int				ft_env(t_token *token); // TO CHECK
int				cd(t_token *token); // TO CHECK
// int				unset(t_token *token); // TODO

// Builtins  - Annex

int				chdir_failed(t_token *token); // TO CHECK
void			replace_env_usd(t_token *token, char *usd); // TO CHECK
int				unset_failed(char *arg); // TO CHECK
// void			dir_backward(char *init_dir, t_token *token);
// void			dir_further(char *init_dir, t_token *token);

// Utils

int				ft_strcmp(const char *s1, const char *s2); // TO CHECK
int				ft_isaldig(char *arg); // TO CHECK
char			*ft_strncpy(char *dest, char *src, unsigned int n); // TO CHECK / UNUSED FOR THE MOMENT

// Free

void			free_split(char *path[]); // TO CHECK
void			free_token(t_token **head);
void			free_env(t_env **envi);

// Others

extern void 	rl_replace_line (const char *, int);
extern void		rl_clear_history(void);
#endif
