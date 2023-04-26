#include "../minishell.h"

/**
 * Takes the input and parses it to then call the
 * appropriate functions to execute the needed commands
 *
 * @param [*input] the input to parse.
 * @param [*envi] our own environment.
 *
 * @return returns nothing but calls the needed function
 * to execute the parsing
 */
void	parser(char	*input, t_env *envi)
{
	t_token	*head;
	int		i;

	i = 0;
	head = NULL;
	if (!check_quotes(input))
	{
		perror("Issue with the quotes");
		return ;
	}
	while (input[i])
	{
		i = sequencer(&head, input, envi, i);
		if (input[i] == '|')
			i++;
	}
	// for (t_token *tmp = head; tmp; tmp = tmp->next)
	// {
	// 	printf("==== parser ====\n");
	// 	printf("cmd: %s\n", tmp->cmd);
	// 	for (int i = 0; tmp->arg[i]; i++)
	// 		printf("arg[%d]: %s\n", i, tmp->arg[i]);
	// 	printf("fdread: %d\n", tmp->fdread);
	// 	printf("fdwrite: %d\n", tmp->fdwrite);
	// }
	replace_usd(head);
	execution(head);
	free_token(&head);
}
