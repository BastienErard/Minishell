/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isaldig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:30 by berard            #+#    #+#             */
/*   Updated: 2023/04/10 17:08:43 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isaldig(char c)
{
	if (c < 48 || (c > 57 && c < 65) || c > 122)
		return (0);
	return (1);
}

int	ft_isaldig_eg(char c)
{
	if (c == '=')
		return (1);
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
				continue ;
			else
			{
				flag = 0;
				break ;
			}
		}
	}
	return (flag);
}
