/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:11:18 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 21:24:22 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (ft_strdup(""));
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next_str(char *r_str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (r_str[i] && r_str[i] != '\n')
		i++;
	if (!r_str[i])
	{
		free(r_str);
		return (NULL);
	}
	buff = malloc((ft_strlen(r_str) - i) + 1);
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (r_str[i])
		buff[j++] = r_str[i++];
	buff[j] = '\0';
	free(r_str);
	return (buff);
}
