/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:43 by berard            #+#    #+#             */
/*   Updated: 2023/04/10 13:39:40 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/**
 * Export command in Bash defines environment variables that can be
 * used by processes and child processes.
*/
int	export(t_token *token)
{
	int		i;
	t_env	*new;

	i = -1;
	if (!token->arg[0])
		return (export_print(token));
	else
	{
		while (token->arg[++i])
		{
			new = malloc(sizeof(t_env));
			new->var = ft_split(token->arg[i], '=');
			new->next = NULL;
			add_last_export(&token->env, new);
		}
	}
	i = -1;
	while (token->arg[++i])
		if (ft_isalpha(token->arg[i][0]) == 0 || isaldig_eg(token->arg[i]) == 0)
			return (export_failed(token->arg[i]));
	return (EXIT_SUCCESS);
}

int	export_print(t_token *token)
{
	int		index;
	t_env	*tmp;

	index = 1;
	az_env(token);
	tmp = token->env;
	while (tmp && (index <= token->env_len))
	{
		if (tmp->alpha == index)
		{
			ft_putstr_fd("declare -x ", 2);
			ft_putstr_fd(tmp->var[0], 2);
			ft_putstr_fd("=\"", 2);
			ft_putstr_fd(tmp->var[1], 2);
			ft_putstr_fd("\"\n", 2);
			index++;
			tmp = token->env;
		}
		else
			tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	export_failed(char *arg)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

/* adds the element to the end of the linked list */
void	add_last_export(t_env **head, t_env *new)
{
	t_env	*tmp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = get_last_export(*head);
	tmp->next = new;
}

/* returns the last element of the t_env list*/
t_env	*get_last_export(t_env *head)
{
	t_env	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
