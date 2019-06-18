/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:37:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/03/07 12:10:54 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_endln(char **stack, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i])
		i++;
	if (stack[fd][i] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, i);
		temp = ft_strdup(&stack[fd][i + 1]);
		ft_strdel(&stack[fd]);
		stack[fd] = temp;
	}
	else
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

static int	read_file(const int fd, char **line, char **stack)
{
	int		ret;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(stack[fd], buf);
		ft_strdel(&stack[fd]);
		stack[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stack[fd][0] == '\0')
		return (0);
	return (check_endln(stack, line, fd));
}

int			get_next_line(const int fd, char **line)
{
	static char *stack[FD_MAX];

	if (fd < 0 || fd > FD_MAX || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!stack[fd])
		stack[fd] = ft_strnew(1);
	return (read_file(fd, line, stack));
}
