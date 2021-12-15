/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:39:23 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/15 14:29:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "LIBFT/libft.h"

typedef struct s_frag
{
	char			*content;
	int				type;
	struct s_frag	*prev;
	struct s_frag	*next;
}					t_frag;

typedef struct s_cmd
{
	char	*line;
	t_frag	*frags;
}			t_cmd;

typedef struct s_data
{
	char	*line;
	char 	*old_line;
	t_list	*cmds;
}			t_data;

// PARSER DE COMMANDE
int 	check_quote(char *str);
int		split_cmds(t_data *data, char *str);

// UTILS INUTILS
void	aff_lst(t_list *lst);
void	delst(void	*content);
void	del_tab(char **tab);

// FRAG UTILS
t_frag	*frag_new(char *content, int type);
t_frag	*frag_last(t_frag *cmd);
void	frag_addback(t_frag **cmd, t_frag *new);
void	frag_clear(t_frag **cmd);

#endif
