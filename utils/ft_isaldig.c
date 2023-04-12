/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isaldig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:30 by berard            #+#    #+#             */
/*   Updated: 2023/04/12 14:30:07 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isaldig_char(char c)
{
	if (c < 48 || (c > 57 && c < 65) || c > 122)
		return (0);
	return (1);
}

int	aldig(char *arg)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (arg[++i] != '\0')
	{
		if (arg[i] < 48 || (arg[i] > 57 && arg[i] < 65)
			|| arg[i] > 122)
		{
			if (arg[i] == '=')
				break ;
			else
			{
				flag = 0;
				break ;
			}
		}
	}
	return (flag);
}
