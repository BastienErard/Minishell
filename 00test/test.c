// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/30 10:38:18 by berard            #+#    #+#             */
// /*   Updated: 2023/04/15 18:31:05 by tastybao         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// int	main(int argc, char *argv[])
// {
// 	char **parse;

// 	parse = split_shell(argv[1]);
// 	printf("This is parse[0] : %s\n", parse[0]);
// 	printf("This is parse[1] : %s\n", parse[1]);
// 	printf("This is parse[2] : %s\n", parse[2]);
// 	return (0);
// }

// char	**split_shell(char *arg)
// {
// 	char	**parse;
// 	char	*tmp;
// 	int		i;

// 	i = -1;
// 	tmp = NULL;
// 	parse = malloc(sizeof(char *) * 3);
// 	if (!parse)
// 		return (NULL);
// 	while (arg[++i] != '\0' && arg[i] != '=')
// 		tmp[i] = arg[i];
// 	parse[0] = ft_strdup(tmp);
// 	if (ft_strchr(arg, '=') && arg[i + 1] == '\0')
// 		parse[1] = ft_strdup("");
// 	else if (ft_strchr(arg, '=') && arg[i + 1] != '\0')
// 		parse[1] = ft_strdup(&arg[i + 1]);
// 	else
// 		parse[1] = NULL;
// 	parse[2] = NULL;
// 	return (parse);
// }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	len;
// 	int		i;
// 	char	*ptr;

// 	len = ft_strlen(s1) + 1;
// 	i = 0;
// 	ptr = malloc(len * sizeof(char));
// 	if (ptr == (NULL))
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (i < ((int)ft_strlen(s) + 1))
// 	{
// 		if (((char *) s)[i] == (char)c)
// 			return (&((char *)s)[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
