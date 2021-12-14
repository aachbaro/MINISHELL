/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/14 13:00:50 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char *str;

	while(strncmp((str = readline("mdmadam>")), "exit", 4))
	{
		if (strncmp(str, "getenv", 6) == 0)
			printf("%s", getenv("PATH"));
		add_history(str);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
