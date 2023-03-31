/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:44 by berard            #+#    #+#             */
/*   Updated: 2023/03/31 09:19:54 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * CD is used in command line to change the current working directory
 * of the shell or program to a specified directory.
*/
void	cd(t_token *token)
{
	char	init_dir[MAXPATHLEN];

	if (getcwd(init_dir, MAXPATHLEN) == NULL)
		return (perror("Error with getcwd()"));
	if (chdir(token->arg[0]) != 0)
		chdir_failed(token);
}

void	chdir_failed(t_token *token)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(token->arg[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

// Inutile car chdir(..), chdir(.) ou chdir(path) est valide...

// !!!! Doit-on gérer cd sans arg ou cd ~? Problèmatique liée à l'env.
// void	cd(t_token *token)
// {
// 	char	init_dir[MAXPATHLEN];

// 	if (getcwd(init_dir, MAXPATHLEN) == NULL)
// 		return (perror("Error with getcwd()"));
// 	if (ft_strcmp(token->arg[0], ".") == 0)
// 		return ;
// 	else if (ft_strcmp(token->arg[0], "..") == 0)
// 		dir_backward(init_dir, token);
// 	else
// 		dir_further(init_dir, token);
// }

// void	dir_backward(char *init_dir, t_token *token)
// {
// 	char			new_dir[MAXPATHLEN];
// 	int				i;
// 	unsigned int	size_ref;

// 	i = -1;
// 	while (init_dir[++i] != '\0')
// 	{
// 		if (init_dir[i] == '/')
// 			size_ref = i;
// 	}
// 	ft_strncpy(new_dir, init_dir, size_ref);
// 	if (chdir(new_dir) != 0)
// 		chdir_failed(token);
// }

// void	dir_further(char *init_dir, t_token *token)
// {
// 	char	new_dir[MAXPATHLEN];
// 	int		i;

// 	i = 0;
// 	if (init_dir[i] == '/')
// 	{
// 		if (chdir(init_dir) != 0)
// 			chdir_failed(token);
// 	}
// 	ft_strncpy(new_dir, init_dir, ft_strlen(init_dir));
// 	ft_strlcat(new_dir, "/", MAXPATHLEN);
// 	ft_strlcat(new_dir, init_dir, MAXPATHLEN);
// 	if (chdir(new_dir) != 0)
// 		chdir_failed(token);
// }
