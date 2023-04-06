/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:28:43 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/06 13:03:51 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* frees the t_token linked list entirely */
void	free_token(t_token **head)
{
	t_token	*tmp;
	t_token	*stock;
	int		i;

	stock = *head;
	while (stock)
	{
		i = -1;
		tmp = stock;
		stock = stock->next;
		while (tmp->arg[++i])
			free(tmp->arg[i]);
		free(tmp->arg);
		free(tmp->cmd);
		free(tmp);
	}
	*head = NULL;
}

/* frees the t_env linked list entirely */
void	free_env(t_env **envi)
{
	t_env	*tmp;
	t_env	*stock;
	int		i;

	stock = *envi;
	while (stock)
	{
		i = -1;
		tmp = stock;
		stock = stock->next;
		while (tmp->var[++i])
			free(tmp->var[i]);
		free(tmp->var);
		free(tmp);
	}
	*envi = NULL;
}
