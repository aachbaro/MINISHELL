/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/13 16:25:53 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

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
