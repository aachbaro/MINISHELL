/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:46:10 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/17 18:11:36 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	line_to_exe(t_data *data)
{
	int	i;

	i = 0;
	if (line_to_tokens(data) == -1)
		return (-1);
	while (data->cmds[i].line)
	{
		if (tkn_to_exe(data, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	prompt(t_data *data)
{
	data->line = readline("~>");
	if (!data->old_line || (ft_strncmp(data->line, data->old_line,
		ft_strlen(data->line)) || ft_strlen(data->old_line)
			!= ft_strlen(data->line)))
		add_history(data->line);
	free(data->old_line);
	data->old_line = ft_strdup(data->line);
	if (!data->old_line)
		return (-1);
	return (0);
}
