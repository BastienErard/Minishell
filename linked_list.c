/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:26:43 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/27 15:21:51 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* takes the head of the list and the command to add
	as input, then adds them to the end of the linked
	list */
// void	add_token(t_token **head, char **command)
// {
// 	t_token	*new;
// 	t_token	*tmp;
// 	int		i;

// 	i = -1;
// 	new = malloc(sizeof(t_token));
// 	if (!new)
// 		return (perror("issue malloc adding element to linked list"));
// 	while (command[++i] != NULL)
// 		ft_strlcpy(new->command[i], command[i], ft_strlen(command[i]) + 1);
// 	new->type = 0;
// 	new->next = NULL;
// 	if (*head == NULL)
// 	{
// 		*head = new;
// 		return;
// 	}
// 	tmp = get_last(*head);
// 	tmp->next = new;
// }

/* adds the element to the end of the linked list */
void	add_last(t_token **head, t_token *new)
{
	t_token		*tmp;

	if (*head == NULL)
	{
		*head = new;
		return;
	}
	tmp = get_last(*head);
	tmp->next = new;
}

/* returns the last element of the t_token list*/
t_token	*get_last(t_token *head)
{
	t_token	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

/* prints the commands of the t_token linked list */
void	print_list(t_token *head)
{
	t_token	*tmp;
	int	j = -1;
	tmp = head;

	while (tmp)
	{
		printf("%s ", tmp->cmd);
		while (tmp->arg[++j])
		{
			printf(" %s ", tmp->arg[j]);
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
