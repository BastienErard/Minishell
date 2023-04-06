/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:55:02 by berard            #+#    #+#             */
/*   Updated: 2023/04/06 13:30:32 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
* The unset command is used to unset or delete shell variables and functions.
* When a variable or function is unset using unset, its value and attributes are
* removed, making it undefined in the current shell session.
*/
int	unset(t_token *token)
{
	int		i;
	t_env	*tmp;

	i = -1;
	while (token->arg[++i])
	{
		tmp = token->env;
		while (tmp)
		{
			if (ft_strcmp(token->arg[i], tmp->var[0]) == 0)
			{
				free_slot_env(&token->env, tmp);
				break ;
			}
			tmp = tmp->next;
		}
	}
	i = -1;
	while (token->arg[++i])
		if (ft_isalpha(token->arg[i][0]) == 0 || ft_isaldig(token->arg[i]) == 0)
			return (unset_failed(token->arg[i]));
	return (EXIT_SUCCESS);
}

void	free_slot_env(t_env **head, t_env *slot)
{
	int		i;
	t_env	*prev;

	if (slot == *head)
	{
		*head = slot->next;
	}
	else
	{
		prev = *head;
		while (prev->next != slot)
			prev = prev->next;
		prev->next = slot->next;
	}
	i = -1;
	while (slot->var[++i])
		free(slot->var[i]);
	free(slot->var);
	free(slot);
}

int	unset_failed(char *arg)
{
	ft_putstr_fd("unset: ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}
