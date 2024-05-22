/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:41:20 by aciezadl          #+#    #+#             */
/*   Updated: 2023/12/13 18:25:52 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == 0)
		return (0);
	if (s[i] == '\n')
		return (i + 1);
	while (s[i] != '\n' && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(const char *s)
{
	int		j;
	int		k;
	char	*d;

	j = 0;
	k = ft_strlen2(s);
	d = malloc(k + 1);
	if (d == NULL)
		return (NULL);
	while (j < k)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}

void	ft_cleanbuf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
	{
		while (buf[i + 1] != '\0')
		{
			buf[j] = buf[i + 1];
			i++;
			j++;
		}
	}
	buf[j] = '\0';
}
