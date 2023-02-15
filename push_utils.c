/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:08:01 by mrami             #+#    #+#             */
/*   Updated: 2023/02/15 14:29:09 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_utils.h"

int	ft_words_conut(char *str, int c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != '\0' && str[i] != c)
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[start + i] != '\0') && (i < len))
	{
		dst[j] = s[start + i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

char	**ft_free(char **dst, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		free(dst[j]);
		j++;
	}
	free(dst);
	return (NULL);
}

char	**ft_location(char **dst, char *str, char c)
{
	size_t	i;
	size_t	index;
	int		j;

	i = 0;
	j = 0;
	while (j < ft_words_conut(str, c))
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		index = i;
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (index < i)
		{
			dst[j] = ft_substr(str, index, i - index);
			if (!dst[j])
				return (ft_free(dst, j));
		}
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char *str, char c)
{
	char	**dst;

	if (!str)
		return (NULL);
	dst = (char **)malloc((ft_words_conut(str, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	dst = ft_location(dst, str, c);
	return (dst);
}
