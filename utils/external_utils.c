/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:20 by berard            #+#    #+#             */
/*   Updated: 2023/05/01 09:49:33 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns a double string containing the env */
char	**get_env(t_token *token)
{
	t_env	*tmp;
	char	**genv;
	int		i;

	i = 0;
	tmp = token->env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	genv = malloc(sizeof(char *) * (i + 1));
	tmp = token->env;
	i = -1;
	while (tmp)
	{
		genv[++i] = ft_strjoin(tmp->var[0], "=");
		if (tmp->var[1])
			genv[i] = ft_strjoin(genv[i], tmp->var[1]);
		tmp = tmp->next;
	}
	genv[++i] = NULL;
	return (genv);
}

/* blends it to make the arguments in one char** */
void	make_arg(t_token *token)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (token->arg[i])
		i++;
	token->arg_all = malloc(sizeof(char *) * (i + 2));
	if (!token->arg_all)
		return (perror("Error with malloc during execution of an external"));
	i = -1;
	token->arg_all[++i] = malloc(sizeof(char) * (ft_strlen(token->cmd) + 1));
	if (!token->arg_all[i])
		return (perror("Error with malloc during execution of an external"));
	ft_copyto(token->arg_all[0], token->cmd);
	if (token->arg[0])
	{
		while (token->arg[++j])
		{
			token->arg_all[++i] = malloc(sizeof(char) \
			* (ft_strlen(token->arg[j]) + 1));
			if (!token->arg_all[i])
				return (perror("Error with malloc during external"));
			ft_copyto(token->arg_all[i], token->arg[j]);
		}
	}
	token->arg_all[++i] = NULL;
}

void	ft_copyto(char *token, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		token[i] = str[i];
		i++;
	}
	token[i] = '\0';
}


