/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:00:14 by mrami             #+#    #+#             */
/*   Updated: 2023/03/04 20:16:29 by mrami            ###   ########.fr       */
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
	int	*temp_stack;
	int	counter;
}t_stack;

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_print_error(char *err);
char	*ft_strdup(const char *s1);
int		ft_atoi(char *str);
int		ft_check_dup(int *arr, int len);
int		ft_words_conut(char *str, int c);
int		ft_isdegit(int c);
int		ft_check_alpha(char *str);
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
void	ft_swap_to_a(t_stack *stack_a);
void	ft_swap_to_b(t_stack *stack_b);
void	ft_swap(t_stack *stact_a, int size);
void	ft_rotate(t_stack *stack_r, int len);
void	ft_rotet_a(t_stack *stack_a);
void	ft_rotet_b(t_stack *stack_b);
void	ft_rotet_rev(t_stack *stack_rv, int len);
void	ft_rotet_rev_a(t_stack *stack_a);
void	ft_rotet_rev_b(t_stack *stack_b);
void	ft_push_to_a(t_stack *stack_a, t_stack *stack_b);


#endif // !PUSHSWAP_H