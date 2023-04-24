#include "../minishell.h"

/**
 * This function manages the shell's functions and, if it finds nothing,
 * indicates that the command does not exist.
*/
void	exec_external(t_token *token)
{
	char	**path;
	char	filepath[MAXPATHLEN];
	int		i;

	i = -1;
	token->g_env = get_env(token);
	make_arg(token);
	if (access(token->cmd, X_OK) == 0)
		execve(token->cmd, token->arg_all, token->g_env);
	path = ft_split(getenv("PATH"), ':'); // TODO - Getenv is not optimal
	if (!path)
		return (perror("Error with split during execution of an external"));
	while (path[++i])
	{
		ft_strlcpy(filepath, path[i], sizeof(filepath));
		ft_strlcat(filepath, "/", sizeof(filepath));
		ft_strlcat(filepath, token->cmd, sizeof(filepath));
		if (access(filepath, X_OK) == 0)
		{
			free_split(path);
			execve(filepath, token->arg_all, token->g_env); // ISSUE LS
		}
	}
	free_split(path);
	ft_putstr_fd(token->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

/* returns a double string containing the env */
char	**get_env(t_token *token)
{
	t_env	*tmp;
	char	**genv;
	int		i;

	i = 0;
	tmp = token->env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	genv = malloc(sizeof(char *) * (i + 1));
	tmp = token->env;
	i = -1;
	while (tmp)
	{
		genv[++i] = ft_strjoin(tmp->var[0], "=");
		genv[i] = ft_strjoin(genv[i], tmp->var[1]);
		tmp = tmp->next;
	}
	genv[++i] = NULL;
	return (genv);
}

/* blends it to make the arguments in one char** */
void	make_arg(t_token *token)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (token->arg[i])
		i++;
	token->arg_all = malloc(sizeof(char *) * (i + 2));
	if (!token->arg_all)
		return (perror("Error with malloc during execution of an external"));
	i = -1;
	token->arg_all[++i] = malloc(sizeof(char) * (ft_strlen(token->cmd) + 1));
	if (!token->arg_all[i])
		return (perror("Error with malloc during execution of an external"));
	ft_copyto(token->arg_all[0], token->cmd);
	if (token->arg[0])
	{
		while (token->arg[++j])
		{
			token->arg_all[++i] = malloc(sizeof(char) * (ft_strlen(token->arg[j]) + 1));
			if (!token->arg_all[i])
				return (perror("Error with malloc during execution of an external"));
			ft_copyto(token->arg_all[i], token->arg[j]);
		}
	}
	token->arg_all[++i] = NULL;
}

void	ft_copyto(char *token, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		token[i] = str[i];
		i++;
	}
	token[i] = '\0';
}
