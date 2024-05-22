/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:41:24 by aciezadl          #+#    #+#             */
/*   Updated: 2023/12/14 11:34:24 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check_endl(char *line)
{
	int	h;

	h = 0;
	if (line[h] == '\n')
		return (1);
	while (line[h] != '\n' && line[h])
	{
		h++;
		if (line[h] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_copi(char const *s1, char const *s2, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (j < ft_strlen2(s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	tt;
	char	*res;

	if (!s1 || !s2)
		return (0);
	tt = ft_strlen(s1) + ft_strlen2(s2);
	res = malloc(tt + 1);
	if (!res)
		return (0);
	res = ft_copi(s1, s2, res);
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE];
	char		*line;
	int			result;

	result = BUFFER_SIZE;
	if (fd == -1 || read(fd, buf[fd], 0) < 0 || BUFFER_SIZE == 0)
		return (0);
	line = malloc(1);
	line[0] = '\0';
	if (buf[fd][0])
		line = ft_strjoin(line, buf[fd]);
	while (result == BUFFER_SIZE)
	{
		if (ft_check_endl(line) == 1)
			break ;
		result = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][result] = '\0';
		line = ft_strjoin(line, buf[fd]);
		if (!line)
			return (NULL);
	}
	ft_cleanbuf(buf[fd]);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*ligne;
// 	int		i;

// 	i = 1;
// 	fd = open("example.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	while (1)
// 	{
// 		ligne = get_next_line(fd);
// 		if (ligne == NULL)
// 		{
// 			printf("%s", ligne);
// 			break ;
// 		}
// 		printf("%d: %s", i, ligne);
// 		free(ligne);
// 		i++;
// 	}
// 	return (0);
// }
