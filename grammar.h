/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:24:29 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/31 14:43:52 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

/* struct used for the env */
typedef struct s_env
{
	char			**var;
	struct s_env	*next;

}				t_env;

/* struct used to tokenize the input */
typedef struct s_token
{
	int					type;
	int					flag_env; //if == 1, then use env variables
	int					i;
	int					pos;
	int					file_type;
	int					fdwrite;
	int					fdread;
	char				*cmd;
	char				**arg;
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
