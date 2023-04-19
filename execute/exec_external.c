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
	char	**g_env = get_env(token);
	if (access(token->cmd, X_OK) == 0)
		execve(token->cmd, token->arg, g_env);
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
			printf("path is %s\n", filepath);
			free_split(path);
			execve(filepath, token->arg, g_env); // ISSUE LS
		}
	}
	free_split(path);
	ft_putstr_fd(token->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}

// /**
//  * This function manages the shell's functions and, if it finds nothing,
//  * indicates that the command does not exist.
// */
// void	exec_external(t_token *token)
// {
// 	char	**path;
// 	char	filepath[MAXPATHLEN];
// 	int		i;
// 	static char	**arguments;

// 	i = -1;
// 	make_arg(token, arguments);
// 	char	**g_env = get_env(token);
// 	if (access(token->cmd, X_OK) == 0)
// 		execve(token->cmd, arguments, g_env);
// 	path = ft_split(getenv("PATH"), ':'); // TODO - Getenv is not optimal
// 	if (!path)
// 		return (perror("Error with split during execution of an external"));
// 	while (path[++i])
// 	{
// 		ft_strlcpy(filepath, path[i], sizeof(filepath));
// 		ft_strlcat(filepath, "/", sizeof(filepath));
// 		ft_strlcat(filepath, token->cmd, sizeof(filepath));
// 		if (access(filepath, X_OK) == 0)
// 		{
// 			printf("path is %s\n", filepath);
// 			free_split(path);
// 			execve(filepath, arguments, g_env); // ISSUE LS
// 		}
// 	}
// 	free_split(path);
// 	ft_putstr_fd(token->cmd, 2);
// 	ft_putstr_fd(": command not found\n", 2);
// }

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
void	make_arg(t_token *token, char **arguments)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = token->arg;
	while (tmp[i])
		i++;
	arguments = malloc(sizeof(char *) * i + 2);
	i = -1;
	arguments[++i] = malloc(sizeof(char) * ft_strlen(token->cmd) + 1);
	ft_strlcpy(arguments[i], token->cmd, ft_strlen(tmp[i]) + 1);
	while (tmp[++i])
	{
		arguments[i] = malloc(sizeof(char) * (ft_strlen(tmp[i]) + 1));
		ft_strlcpy(arguments[i], tmp[i], ft_strlen(tmp[i]) + 1);
	}
	arguments[++i] = NULL;
}
