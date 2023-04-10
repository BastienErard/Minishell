/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:43 by berard            #+#    #+#             */
/*   Updated: 2023/04/10 17:30:30 by berard           ###   ########.fr       */
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
	int		exit_code;
	t_env	*new;

	i = -1;
	exit_code = 0;
	if (!token->arg[0])
		return (export_print(token));
	else
	{
		while (token->arg[++i])
		{
			if (ft_isalpha(token->arg[i][0]) != 0 && aldig(token->arg[i]) != 0)
				// export_add_replace(token);
			{
				new = malloc(sizeof(t_env));
				new->var = ft_split(token->arg[i], '=');
				new->next = NULL;
				add_last_export(&token->env, new);
			}
			exit_code += export_check(token->arg[i]);
		}
	}
	if (exit_code > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// void	export_add_replace(t_token *token)
// {
// 	t_env	*new;
// 	t_env	*tmp;

// 	tmp = token->env;
// 	while (tmp)
// 	{
// 		if (ft_strcmp)
// 	}
// }

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

int	export_check(char *arg)
{
	int	i;
	int	exit_code;

	i = -1;
	exit_code = 0;
	while (arg[++i] != '\0')
	{
		if (ft_isalpha(arg[0]) == 0 || ft_isaldig_eg(arg[i]) == 0)
		{
			ft_putstr_fd("export: ", 2);
			ft_putstr_fd("`", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			exit_code = 1;
			break ;
		}
	}
	return (exit_code);
}
