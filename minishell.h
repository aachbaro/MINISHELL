/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:39:23 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/16 18:32:04 by aachbaro         ###   ########.fr       */
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
# define TYPE_QUOTE 0
# define TYPE_DBLQUOTE 1
# define TYPE_VAR 2
# define TYPE_REDIN 3
# define TYPE_REDOUT 4
# define TYPE_HRDOC 5
# define TYPE_APPEND 6
# define TYPE_NAME 7

typedef struct s_tkn
{
	char			*content;
	int				type;
	struct s_tkn	*prev;
	struct s_tkn	*next;
}					t_tkn;

typedef struct s_cmd
{
	char	*line;
	char	*path;
	char	**args;
	t_tkn	*tkn;
}			t_cmd;

typedef struct s_data
{
	char	*line;
	char 	*old_line;
	t_cmd	*cmds;
}			t_data;

// PARSER DE COMMANDE
int 	check_quote(char *str);
int		split_cmds(t_data *data, char *str);
int		line_to_tokens(t_data *data);
int		pars_alnum(t_data *data, int start, int cmd);
int		pars_quote(t_data *data, int start, int cmd);
int		pars_dblquote(t_data *data, int start, int cmd);
int		pars_lessthan(t_data *data, int start, int cmd);
int		pars_morethan(t_data *data, int start, int cmd);
int		pars_var(t_data *data, int start, int cmd);

// UTILS INUTILS
void	aff_lst(t_list *lst);
void	delst(void	*content);
void	del_tab(char **tab);
void	del_cmd(t_data *data);
char	*ft_strndup(const char *s, int n);

// FRAG UTILS
t_tkn	*tkn_new(char *content, int type);
t_tkn	*tkn_last(t_tkn *cmd);
void	tkn_addback(t_tkn **cmd, t_tkn *new);
void	tkn_clear(t_tkn **cmd);

#endif
