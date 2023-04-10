/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_linked.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:08:42 by berard            #+#    #+#             */
/*   Updated: 2023/04/10 15:48:17 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
