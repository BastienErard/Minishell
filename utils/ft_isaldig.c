/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isaldig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:30 by berard            #+#    #+#             */
/*   Updated: 2023/04/06 17:38:33 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isaldig(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (arg[i] < 48 || (arg[i] > 57 && arg[i] < 65)
			|| arg[i] > 122)
			return (0);
	}
	return (1);
}

int	isaldig_eg(char *arg)
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
				flag = 0;
				if (arg[i] == '=')
					flag = 1;
			}
	}
	return (flag);
}
