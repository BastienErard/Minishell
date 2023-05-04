/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacebar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:28:34 by berard            #+#    #+#             */
/*   Updated: 2023/05/04 17:37:35 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	space(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (input[i] != 32 && input[i] != '\t')
			return (1);
	return (0);
}
