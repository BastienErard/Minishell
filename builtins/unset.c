/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:55:02 by berard            #+#    #+#             */
/*   Updated: 2023/04/03 16:12:20 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	unset(t_token *token)
// {
// 	int	i;
// 	int	flag;

// 	i = -1;
// 	flag = 0;
// 	while (token->arg[++i])
// 	{
// 		if (ft_isalpha(token->arg[i][0]) == 0 || ft_isaldig(token->arg[i]) == 0)
// 			flag = unset(failed(token->arg[i]));
// 	}
// 	i = -1;
// 	while (token->arg[++i])
// 	{
// 		while (token->env)
// 		{
// 			if (ft_strcmp(token->arg[i], token->env->var[0]) == 0)
// 				// COMPLETER
// 		}
// 	}
// 	if (flag == 1)
// 		return (errno);
// 	return (EXIT_SUCCESS);
// }

// int	unset_failed(char *arg)
// {
// 	ft_putstr_fd("unset : ", 2);
// 	ft_putstr_fd("`", 2);
// 	ft_putstr_fd(arg, 2);
// 	ft_putstr_fd("': not a valid identifier\n", 2);
// 	return (1);
// }
