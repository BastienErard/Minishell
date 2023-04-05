/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_usd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:01:15 by berard            #+#    #+#             */
/*   Updated: 2023/04/05 11:05:20 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * This function is used to replace environment variables (a $ followed
 * by a sequence of characters) as well as $?.
 * $home should return the affiliated environment variable, while $?
 * should be substituted with the exit status of the last foreground
 * pipeline executed.
*/
void	replace_usd(t_token *token)
{
	int	i;

	i = -1;
	while (token->arg[++i])
	{
		if (token->arg[i][0] == '$' && token->flag_env)
		{
			if (token->arg[i][1] == '?')
			{
				free(token->arg[i]);
				token->arg[i] = ft_itoa(g_exit_code);
			}
			else if (token->arg[i][1] != '\0')
				replace_env_usd(token, token->arg[i]);
		}
	}
}

void	replace_env_usd(t_token *token, char *usd)
{
	// char	*tmp;
	// int		i;

	// i = -1;
	// tmp = malloc(sizeof(char) * ft_strlen(usd));
	// while (usd[++i + 1])
	// 	tmp[i] = usd[i + 1];
	// tmp[i] = '\0';
	// free(usd);
	// usd = ft_strdup(tmp);
	// free(tmp);
	while (token->env && ft_strcmp(usd + 1, token->env->var[0]) != 0)
		token->env = token->env->next;
	if (token->env != NULL)
	{
		free(usd);
		usd = strdup(token->env->var[1]);
	}
	else
	{
		free(usd);
		usd = strdup("");
	}
}
