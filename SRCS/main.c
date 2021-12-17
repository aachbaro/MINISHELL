/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/17 13:52:04 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_splitted_cmd(t_data *data)
{
	int	i;
	t_tkn	*cpy;

	i = 0;
	while (data->cmds[i].line)
	{
		printf("\n\nCOMMAAAAAAAAAAAAAAAAAAANDE\n");
		printf("\ncmds[%d]->line = %s\n", i, data->cmds[i].line);
		cpy = data->cmds[i].tkn;
		while (cpy)
		{
			printf("\nTOKEN\ncontent = %s\ntype = %d\n", cpy->content, cpy->type);
			cpy = cpy->next;
		}
		i++;
	}
}

void	print_cmd_path_args(t_data *data)
{
	int	i;

	i = 0;
	printf("PATH = %s\n", data->cmds[0].path);
	while (data->cmds[0].args[i])
	{
		printf("arg [%d] = %s\n", i, data->cmds[0].args[i]);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	data.cmds = NULL;
	data.old_line = NULL;
	data.env = env;
	if (ac || av)
		;
	while(ft_strncmp((data.line = readline("mdmadam>")), "exit", 4))
	{
		if (data.cmds)
			del_cmd(&data);
		if (!data.old_line || ft_strncmp(data.line,
					data.old_line, ft_strlen(data.line)))
			add_history(data.line);
		free(data.old_line);
		data.old_line = ft_strdup(data.line);
		if (line_to_tokens(&data) == -1)
			printf("errorline to tkn");
		if (tkn_to_exe(&data, 0) == -1)
			printf("command not foud");
		print_cmd_path_args(&data);
		exe_path(&data, 0);
		free(data.line);
	}
	return (0);
}
