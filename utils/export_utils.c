/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:21:02 by berard            #+#    #+#             */
/*   Updated: 2023/05/01 16:32:38 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup_pimp(const char *s1)
{
	size_t	len;
	int		i;
	int		j;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	i = 0;
	j = 0;
	ptr = malloc(len * sizeof(char));
	if (ptr == (NULL))
		return (NULL);
	while (s1[i])
	{
		while (s1[i] && s1[i] == '\"')
			i++;
		if (s1[i] == '\0')
			break ;
		ptr[j] = s1[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
