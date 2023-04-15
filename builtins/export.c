/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:43 by berard            #+#    #+#             */
/*   Updated: 2023/04/15 18:48:28 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/**
 * Export command in Bash defines environment variables that can be
 * used by processes and child processes.
*/
int	export(t_token *token)
{
	int		i;
	int		flag;
	t_env	*new;

	i = -1;
	flag = 0;
	if (!token->arg[0])
		return (export_print(token));
	while (token->arg[++i])
	{
		if (ft_isalpha(token->arg[i][0]) != 0 && aldig(token->arg[i]) != 0)
			// export_parsing(token, token->arg[i]);
		{
			new = malloc(sizeof(t_env));
			new->var = ft_split(token->arg[i], '=');
			new->next = NULL;
			add_last_export(&token->env, new);
		}
		else
			flag = export_error(token->arg[i]);
	}
	if (flag > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// char	**split_shell(char *arg)
// {
// 	char	**parse;
// 	char	tmp[1024];
// 	int		i;

// 	i = -1;
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

// int	export_parsing(t_token *token, char *arg)
// {
// 	char	**parse;
// 	int		i;

// 	i = 1;
// 	// parse = ft_split(arg, '=');
// 	parse = split_shell(arg);
// 	if (!parse)
// 		return (0);
// 	if (!ft_strchr(arg, '='))
// 		export_compare(token, parse);
// 	else if (ft_strchr(arg, '=') && parse[1] == NULL)
// 	{
// 		parse[1] = ft_strdup("");
// 		// parse[2] = NULL;
// 		export_compare(token, parse);
// 	}
// 	else
// 	{
// 		while (parse[++i])
// 		{
// 			parse[1] = ft_strjoin(parse[1], "=");
// 			parse[1] = ft_strjoin(parse[1], parse[i]);
// 		}
// 		export_compare(token, parse);
// 	}
// 	return (1);
// }

// char	*ft_strjoin_pimp(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	char	*ptr;

// 	i = -1;
// 	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	while (s1[++i])
// 		ptr[i] = s1[i];
// 	i--;
// 	while (s2[++i - ft_strlen(s1)])
// 		ptr[i] = s2[i - ft_strlen(s1)];
// 	ptr[i] = '\0';
// 	free ((char *)s1);
// 	return (ptr);
// }


// void	export_compare(t_token *token, char **parse)
// {
// 	int		flag;
// 	t_env	*tmp;

// 	flag = 0;
// 	tmp = token->env;
// 	while (tmp)
// 	{
// 		if (ft_strcmp(tmp->var[0], parse[0]) == 0)
// 		{
// 			if (parse[1])
// 			{
// 				free (tmp->var[1]);
// 				tmp->var[1] = ft_strdup(parse[1]);
// 			}
// 			free_split(parse);
// 			flag = 1;
// 			break;
// 		}
// 		tmp= tmp->next;
// 	}
// 	if (flag == 0)
// 		export_add_list(token, parse);
// }

// int	export_add_list(t_token *token, char **parse)
// {
// 	t_env	*new;

// 	new = malloc(sizeof(t_env));
// 	if (!new)
// 		return (0);
// 	new->var = parse;
// 	new->next = NULL;
// 	add_last_export(&token->env, new);
// 	return (1);
// }

//*********************************************************************//
int	export_print(t_token *token)
{
	int		index;
	t_env	*tmp;

	index = az_env(token);
	tmp = token->env;
	while (tmp && (index <= token->env_len))
	{
		if (tmp->alpha == index)
		{
			ft_putstr_fd("declare -x ", 2);
			ft_putstr_fd(tmp->var[0], 2);
			if (tmp->var[1] != NULL)
			{
				ft_putstr_fd("=\"", 2);
				ft_putstr_fd(tmp->var[1], 2);
				ft_putstr_fd("\"", 2);
			}
			ft_putstr_fd("\n", 2);
			index++;
			tmp = token->env;
		}
		else
			tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	export_error(char *arg)
{
	int	flag;

	flag = 1;
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (flag);
}
