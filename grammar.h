/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:24:29 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/13 19:56:21 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

/* struct used to tokenize the input */
typedef struct s_token
{
	int					type;
	char				**command;
	struct s_minishell	*next;
	struct s_minishell	*prev;
}				t_token;

/* struct for the command and options (-ls) */
typedef struct s_cmd
{
	int				type;
	char			**command;
	char			**option;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

enum e_token {
	COMMAND = 1,
	PIPE = 2,
	OPTION = 3,
	REDIRECTION = 4,
	ENV = 5,
	PATH = 6,
	LIST = 7,
	EQUAL = 8,
	STRING = 9
};

#endif
