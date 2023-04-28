
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

//Global

extern int		g_exit_code;

//lexer.c

int				sequencer(t_token **head, char *input, t_env *envi, int index);
void			get_cmd(t_token *new, char *input);
void			get_redirection(t_token *new, char *input);
void			get_arg(t_token *new, char *input);
int				word_len(char *input, int i);
int				check_quotes(char *input);

//lexer_utils.c

int				isredi(char c);
int				isdeli(char c, char flag);
int				ft_isaspace(char c);
void			space_index(t_token *new, char *input);
int				checkquotes(char *input, char quote, int i);
void			initialisation(t_token	*head);

//linked_list.c

void			add_token(t_token **head, char **command);
void			add_last(t_token **head, t_token *new);
t_token			*get_last(t_token *head);
void			print_list(t_token *head);

//get.c

void			get_word(t_token *new, char *input);
void			get_squote(t_token *new, char *input);
void			get_dquote(t_token *new, char *input);
int				mystrcspn(char *s, char *reject, int i);
int				env_handler(t_token *new, char *input, int j);

//redirection.c

void			r_left(t_token *new, char *input);
void			rr_left(t_token *new, char *input);	//TODO not finished
void			r_right(t_token *new, char *input);
void			rr_right(t_token *new, char *input);
char			*get_filename(t_token *new, char *input);

//parser.c

void			parser(char *input, t_env *envi);
void			initialize_sequence(t_token *new, t_env *envi, int index);

//env_utils.c

void			init_env(t_env **envi, char **env);
void			add_env(t_env **envi, char *env);
int				az_env(t_token *token);
void			env_init(t_token *token);

//Signals

void			signals_init(void (*signals_handle)(int)); // TO CHECK
void			signals_handle_input(int sig); // TO CHECK
void			signals_handle_execution(int sig); // TO CHECK
void			init_termios(void); // TO CHECK

//Execution

void			execution(t_token *token); // TO COMPLETE
int				is_builtins(t_token *token); // TO CHECK
void			replace_usd(t_token *token); // TO CHECK
char			*rep_env_usd(t_token *token, char *usd); // TO CHECK
void			exec_cmd(t_token *token); // TO COMPLETE
void			exec_cmds(t_token *token);
void			exec_external(t_token *token); // TO CHECK
int				exec_builtins(t_token *token); // TO ADAPT && COMPLETE
char			**get_env(t_token *token);
void			fuckit(char *genv, char *var1, char *var2);
void			ft_copyto(char *token, char *str);
void			make_arg(t_token *token);
void			exec_ext_bis(t_token *token, char **path, char *arg);
void			exec_check_path(t_token *token);
void			exec_external_code(t_token *token);
char			**exec_split_path(t_token *token);

//Builtins

int				echo(t_token *token); // TO CHECK
int				pwd(void); // TO CHECK
void			ft_exit(t_token *token); // TO CHECK
int				ft_env(t_token *token); // TO CHECK
int				cd(t_token *token); // TO CHECK
int				unset(t_token *token); // TO CHECK
int				export(t_token *token); // TO CHECK

//Builtins  - Annex

int				cd_failed(t_token *token); // TO CHECK
void			cd_changepwd(t_token *token, char *path);
int				unset_check(char *arg); // TO CHECK
void			unset_free_slot(t_env **head, t_env *slot);
void			export_parsing(t_token *token, char *arg); // TO CHECK
void			export_compare(t_token *token, char **parse); // TO CHECK
int				export_error(char *arg);
int				export_print(t_token *token); // TO CHECK
void			export_add_list(t_token *token, char **parse); // TEST
void			export_add_last(t_env **head, t_env *new); // TO CHECK
t_env			*export_get_last(t_env *head); // TO CHECK
int				env_pathless(t_env *tmp); // TO CHECK
int				env_error(char *str); // TO CHECK
void			exit_arguments(void); // TO CHECK
void			exit_alpha(t_token *token); // TO CHECK
int				exit_control(char *arg); // TO CHECK

//Utils

int				ft_strcmp(const char *s1, const char *s2); // TO CHECK
int				isaldig_char(char c); // TO CHECK
int				aldig(char *arg); // TO CHECK
int				ft_switch_int(t_env *alpha, t_env *beta);
int				space(char *input); // TO CHECK

//Pipes

void			parents(t_token *token, t_pipes *pipes);
void			child(t_token *token, t_pipes *pipes);
void			pipe_start(t_token *token);

//Free

void			free_split(char *path[]); // TO CHECK
void			free_token(t_token **head);
void			free_env(t_env **envi);
void			free_double(t_token *token);

//Others
extern void		rl_replace_line(const char *bob, int test); // RANDOM NAME
extern void		rl_clear_history(void);

#endif
