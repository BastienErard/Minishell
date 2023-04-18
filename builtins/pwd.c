/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:15:23 by berard            #+#    #+#             */
/*   Updated: 2023/04/18 19:03:25 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* PWD prints the absolute path of the current working directory to the terminal. */
int	pwd(void)
{
	char	path[MAXPATHLEN];

	if (getcwd(path, MAXPATHLEN) == NULL)
	{
		perror("Error with getcwd()");
		return (errno);
	}
	printf("%s\n", path);
	return (EXIT_SUCCESS);
}
