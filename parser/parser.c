/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/27 17:58:31 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Takes the input and parses it to then call the
 * appropriate functions to execute the needed commands
 *
 * @param [*input] the input to parse.
 *
 * @return returns nothing but calls the needed function
 * to execute the parsing
 */
void	parser(char	*input)
{
	t_token	*head;

	head = NULL;
	sequencer(&head, input);
}

