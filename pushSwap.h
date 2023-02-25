/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:00:14 by mrami             #+#    #+#             */
/*   Updated: 2023/02/25 16:28:59 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<string.h>
# include<stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	counter;
}t_stack;

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_print_error(char *err);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_check_dup(int *arr, int len);
int		ft_words_conut(char *str, int c);
int		ft_isdegit(int c);
int		ft_check_alpha(int args, char const *argv[]);
int		ft_check_max_min(long num);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_free(char **dst, int len);
char	**ft_location(char **dst, char *str, char c);
char	**ft_split(char *str, char c);
int		ft_lenght_args(int argc, char const *argv[]);
char	*ft_get_all_args(int argc, char const *argv[]);
char	*ft_get_all_args(int argc, char const *argv[]);
void	ft_split_to_atio(int argc, char const *argv[], t_stack *stack_a);
int		ft_length_of_spliter(char **spl);

#endif // !PUSHSWAP_H