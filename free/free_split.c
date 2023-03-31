/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:27:07 by berard            #+#    #+#             */
/*   Updated: 2023/03/31 14:32:59 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * This function frees the memory allocated to an array of strings that was
 * created using split. It iterates over each element of the array,
 * frees the memory allocated to the string, and then frees the memory allocated
 * to the array itself.
*/
void	free_split(char *path[])
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
