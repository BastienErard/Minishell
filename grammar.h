/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:24:29 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 14:52:15 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* struct used to tokenize the input */
typedef struct s_token
{
	int					type;
	char				*value;
	struct s_minishell	*next;
	struct s_minishell	*prev;
}				t_token;

enum token {
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
