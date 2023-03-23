/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:24:29 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/23 16:59:13 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

/* struct used to tokenize the input */
typedef struct s_token
{
	int					type;
	int					flag_env; //if == 1, then use env variables
	int					fdwrite;
	int					fdread;
	char				*cmd;
	char				**arg;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;

enum e_token {
	COMMAND = 1,
	ARG = 2,
	PIPE = 3,
	REDIRECTION = 4,
	FILE = 5,
};

#endif
