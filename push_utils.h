/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:08:28 by mrami             #+#    #+#             */
/*   Updated: 2023/02/14 18:51:25 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_UTILS_H
# define PUSH_UTILS_H

# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include<stdio.h>

struct	s_result
{
	char	*concat;
	int		coount;
};

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, char const *s2);

#endif // !PUSH_UTILS_H