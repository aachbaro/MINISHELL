/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/14 19:06:16 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	t_data	data;

	data.cmds = NULL;
	data.old_line = NULL;
	while(ft_strncmp((data.line = readline("mdmadam>")), "exit", 4))
	{
		if (data.cmds)
			ft_lstclear(&data.cmds, &free);
		if (!data.old_line || ft_strncmp(data.line,
					data.old_line, ft_strlen(data.line)))
			add_history(data.line);
		free(data.old_line);
		data.old_line = ft_strdup(data.line);
		if (check_quote(data.line))
			printf("error\n");
		if (split_cmds(&data, data.line) == -1)
			return (-1);
		aff_lst(data.cmds);
		free(data.line);
	}
	return (0);
}
