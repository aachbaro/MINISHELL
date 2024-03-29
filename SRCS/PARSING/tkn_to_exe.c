/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_to_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:54:05 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/17 17:06:17 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char 	*get_possible_path(char *cmd, char *str)
{
	char *ret;
	char *tmp;

	tmp = ft_strjoin(str, "/");
	if (!tmp)
		return (NULL);
	ret = ft_strjoin(tmp, cmd);
	free(tmp);
	return (ret);
}

char	*get_path(char *cmd)
{
	char	*path;
	char	**tab;
	int		i;

	path = ft_strdup(getenv("PATH"));
	if (!path)
		return (NULL);
	tab = ft_split(path, ':');
	free(path);
	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		path = get_possible_path(cmd, tab[i]);
		if (!path)
			return (NULL);
		if (!access(path, F_OK))
		{
			del_tab(tab);
			return (path);
		}
		free(path);
		i++;
	}
	del_tab(tab);
	return (ft_strdup(cmd));
}

char	**get_args(t_cmd cmd)
{
	t_tkn	*cpy;
	int		i;
	char	**tab;

	cpy = cmd.tkn;
	i = 0;
	while (cpy && cpy->type < TYPE_REDIN)
	{
		i++;
		cpy = cpy->next;
	}
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	cpy = cmd.tkn;
	i = 0;
	while (cpy && cpy->type < TYPE_REDIN)
	{
		tab[i] = ft_strdup(cpy->content);
		if (!tab[i])
			return (NULL);
		i++;
		cpy = cpy->next;
	}
	tab[i] = NULL;
	return (tab);
}

int	tkn_to_exe(t_data *data, int cmd)
{
	data->cmds[cmd].path = get_path(data->cmds[cmd].tkn->content);
	if (!data->cmds[cmd].path)
		return (-1);
	data->cmds[cmd].args = get_args(data->cmds[cmd]);
	if (!data->cmds[cmd].args)
		return (-1);
	return (0);
}
