/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:15:23 by berard            #+#    #+#             */
/*   Updated: 2023/03/30 11:22:36 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * PWD prints the absolute path of the current working directory to the terminal.
 */
void	pwd(void)
{
	char	path[MAXPATHLEN];

	if (getcwd(path, MAXPATHLEN) == NULL)
		return (perror("Error with getcwd()"));
	printf("%s\n", path);
}
