
#ifndef GRAMMAR_H
# define GRAMMAR_H

/* struct used for the env */
typedef struct s_env
{
	int				alpha;
	char			*path;
	char			**var;
	struct s_env	*next;

}				t_env;

/* struct for the pipes */
typedef struct s_pipes
{
	int		pfd[2];
	int		pid;
}				t_pipes;

/* struct used to tokenize the input */
typedef struct s_token
{
	int					type;
	int					flag_env; //if == 1, then use env variables
	int					i;
	int					pos;
	int					env_len;
	int					file_type;
	int					fdwrite;
	int					fdread;
	char				*cmd;
	char				**arg;
	char				**g_env;
	char				**arg_all;
	t_env				*env;
	struct s_token		*next;
}				t_token;

enum e_token {
	COMMAND = 1,
	ARG = 2,
	PIPE = 3,
	R_LEFT = 4,		// <
	R_RIGHT = 5,	// >
	RR_LEFT = 6,	// <<
	RR_RIGHT = 7,	// >>
};

#endif
