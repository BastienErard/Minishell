/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:18 by berard            #+#    #+#             */
/*   Updated: 2023/03/30 17:51:17 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	main(int argc, char *argv[])
// {
// 	cd(argv);
// 	return (0);
// }

// void	cd(char *argv[])
// {
// 	char	init_dir[MAXPATHLEN];

// 	if (getcwd(init_dir, MAXPATHLEN) == NULL)
// 		return (perror("Error with getcwd()"));
// 	if (ft_strcmp(argv[1], ".") == 0)
// 		return ;
// 	else if (ft_strcmp(argv[1], "..") == 0)
// 		dir_backward(init_dir, argv);
// 	else
// 		dir_further(init_dir, argv);
// }

// void	dir_backward(char *init_dir, char *argv[])
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
// 		chdir_failed(argv);
// }

// void	dir_further(char *init_dir, char *argv[])
// {
// 	char	new_dir[MAXPATHLEN];
// 	int		i;

// 	i = 0;
// 	if (init_dir[i] == '/')
// 	{
// 		if (chdir(init_dir) != 0)
// 			chdir_failed(argv);
// 	}
// 	ft_strncpy(new_dir, init_dir, ft_strlen(init_dir));
// 	ft_strlcat(new_dir, "/", MAXPATHLEN);
// 	ft_strlcat(new_dir, init_dir, MAXPATHLEN);
// 	if (chdir(new_dir) != 0)
// 		chdir_failed(argv);
// }

// void	chdir_failed(char *argv[])
// {
// 	ft_putstr_fd("cd: ", 2);
// 	ft_putstr_fd(argv[1], 2);
// 	ft_putstr_fd(": ", 2);
// 	ft_putstr_fd(": No such file or directory\n", 2);
// }
