/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/03 12:57:29 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Takes the input and parses it to then call the
 * appropriate functions to execute the needed commands
 *
 * @param [*input] the input to parse.
 * @param [*envi] our own environment.
 *
 * @return returns nothing but calls the needed function
 * to execute the parsing
 */
void	parser(char	*input, t_env *envi)
{
	t_token	*head;

	head = NULL;
	sequencer(&head, input, envi);
	free_token(&head);
}

/* takes the env and adds it to the struct
	var[0] == var, var[1] == value of var */
void	init_env(t_env **envi, char **env)
{
	int	i;

	i = -1;
	*envi = NULL;
	while (env[++i])
		add_env(envi, env[i]);
}

/* creates an env element and adds it at the end of the list */
void	add_env(t_env **envi, char *env)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	new->var = ft_split(env, '=');
	if (!new || !new->var)
		perror("issue malloc add_env");
	new->next = NULL;
	if (*envi == NULL)
	{
		*envi = new;
		return ;
	}
	tmp = *envi;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
