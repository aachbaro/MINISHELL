/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/16 19:24:04 by aachbaro         ###   ########.fr       */
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

int	main(void)
{
	t_data	data;

	data.cmds = NULL;
	data.old_line = NULL;
	while(ft_strncmp((data.line = readline("mdmadam>")), "exit", 4))
	{
		if (data.cmds)
			del_cmd(&data);
		if (!data.old_line || ft_strncmp(data.line,
					data.old_line, ft_strlen(data.line)))
			add_history(data.line);
		free(data.old_line);
		data.old_line = ft_strdup(data.line);
		if (line_to_tokens(&data) != -1)
			print_splitted_cmd(&data);
		else
			printf("error\n");
		free(data.line);
	}
	return (0);
}
