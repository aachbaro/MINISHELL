/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:43:26 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/15 14:29:13 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	smpl;
	int	dbl;

	smpl = 0;
	dbl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dbl == 0 && smpl == 0)
			smpl = 1;
		else if (str[i] == '\'' && dbl == 0 && smpl == 1)
			smpl = 0;
		else if (str[i] == '"' && smpl == 0 && dbl == 0)
			dbl = 1;
		else if (str[i] == '"' && smpl == 0 && dbl == 1)
			dbl = 0;
		i++;
	}
	return (dbl + smpl);
}

int	split_cmds(t_data *data, char *str)
{
	char	**tab;
	int		i;

	tab = ft_split(str, '|');
	if (!tab)
		return (-1);
	i = 0;
	while (tab[i])
		ft_lstadd_back(&data->cmds, ft_lstnew((void *)ft_strdup(tab[i++])));
	del_tab(tab);
	return (0);
}	

int	str_to_cmd(char *str)
{
	
}
