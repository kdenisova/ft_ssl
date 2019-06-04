/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:37:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/03/07 11:30:34 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	char *line;
	int fd;
	int i;

	i = 1;
	if (argc == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("%s\n", line);
			ft_strdel(&line);
		}
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				return (-1);
			else
			{
				while (get_next_line(fd, &line) > 0)
				{
					printf("%s\n", line);
					ft_strdel(&line);
				}
			}
			i++;
		}
	}
	//system("leaks a.out");
	return (0);
}
