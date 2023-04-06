/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/05 17:33:03 by tastybao         ###   ########.fr       */
=======
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/06 13:01:08 by fabien           ###   ########.fr       */
>>>>>>> fab
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
	int		i;

	i = 0;
	head = NULL;
	while (input[i])
	{
		i = sequencer(&head, input, envi, i);
		if (input[i] == '|')
			i++;
	}
	replace_usd(head);
	execution(head);
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

/* indexes the env to be printed with env->alpha*/
void	az_env(t_token *token)
{
<<<<<<< HEAD
	// int		i; // UNUSED - Put in comment by Tastybao the great
=======
>>>>>>> fab
	int		buf;
	t_env	*first;
	t_env	*second;

<<<<<<< HEAD
	// i = -1; // UNUSED - Put in comment by Tastybao the great
=======
>>>>>>> fab
	first = token->env;
	second = token->env->next;
	env_init(token);
	while (first || second)
	{
		if (ft_strcmp(first->var[0], second->var[0]) < 0)
		{
			buf = first->alpha;
			first->alpha = second->alpha;
			second->alpha = buf;
		}
		first = first->next;
		second = second->next;
	}
}

/* initialise all the env->alpha */
void	env_init(t_token *token)
{
	t_env	*tmp;
	int		i;

	tmp = token->env;
	i = 0;
	while (tmp)
	{
		tmp->alpha = i;
		i++;
		tmp = tmp->next;
	}
}
