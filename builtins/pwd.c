/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:15:23 by berard            #+#    #+#             */
/*   Updated: 2023/03/29 17:19:18 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * PWD prints the absolute path of the current working directory to the terminal.
 */
void	pwd(void)
{
	char	path[1024];

	if (getcwd(path, sizeof(path)) == NULL)
		return (perror("Error with getcwd()"));
	printf("%s\n", path);
}
