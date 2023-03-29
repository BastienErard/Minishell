/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:44 by berard            #+#    #+#             */
/*   Updated: 2023/03/29 18:36:22 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_token *token)
{
	char	init_dir[1024];
	char	new_dir[1024];

	if (getcwd(init_dir, sizeof(init_dir)) == NULL)
		return (perror("Error with getcwd()"));
	if (ft_strcmp(token->arg[1], ".") == 0)
		return ;
	else if (ft_strcmp(token->arg, "..") == 0)
	{
		new_dir = dir_backward(init_dir, token);
		if (chdir(new_dir) != 0)
			return (perror("chdir() error"));
	}
	else if (ft_strcmp(token->arg[1], "~") == 0 || !token->arg[i])
	{
		new_dir = go_home(init_dir, token);
		if (chdir("HOME") != 0)
			return (perror("chdir() error"));
	}
	else
	{
		new_dir = dir_further(init_dir, token);
		if (chdir(token->arg[1]) != 0)
			{
				ft_putstr_fd("cd: ", 2);
				ft_putstr_fd(token->arg[i], 2);
				ft_putstr_fd(": ", 2);
				return (perror(""));
			}
	}
}

// 1) Faire fonction dir_backward
// 2) Faire fonction dir_further
// 3) Faire fonction go_home
// 4) Faire fonction erreur cd
