/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:15:23 by berard            #+#    #+#             */
/*   Updated: 2023/03/24 16:33:24 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * PWD prints the absolute path of the current working directory to the terminal,
 */
void	pwd(void)
{
	char	path[1080];

	if (getcwd(path, 1080) == NULL)
		return (perror("Error with getcwd"));
	printf("%s\n", path);
}
