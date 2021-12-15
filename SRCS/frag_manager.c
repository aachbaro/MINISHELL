/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:53:44 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/15 14:16:02 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_frag	*frag_new(char *content, int type)
{
	t_frag	*new;

	new = malloc(sizeof(t_frag));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_frag	*frag_last(t_frag *cmd)
{
	t_frag	*cpy;

	cpy = cmd;
	if (cpy)
		while (cpy->next)
			cpy = cpy->next;
	return (cpy);
}

void	frag_addback(t_frag **cmd, t_frag *new)
{
	t_frag	*cpy;

	if (*cmd == NULL)
		*cmd = new;
	else
	{
		cpy = frag_last(*cmd);
		cpy->next = new;
		cpy->next->prev = cpy;
	}
}

void	frag_clear(t_frag **cmd)
{
	t_frag	*cpy;

	while (*cmd)
	{
		cpy = (*cmd)->next;
		free((*cmd)->content);
		free(*cmd);
		*cmd = cpy;
	}
}
