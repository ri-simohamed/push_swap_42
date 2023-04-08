/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:00:14 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 17:53:33 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<string.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

typedef struct s_stack
{
	int	*stack;
	int	counter;
}t_stack;

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_print_error(const char *err);
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
void	ft_push(t_stack *stack_a, t_stack *stack_b);
int		ft_get_max_of_stack(t_stack *stack1);
int		ft__get_min_of_stack(t_stack *stack1);
void	ft_sort_thri_num(t_stack *stack1);
void	ft_sort_five(t_stack *stack1, t_stack *stack2);
int		ft_check_sorting(t_stack *stack1);
void	ft_move_to_top(t_stack *stack1, int numb);
int		ft_calculate_move(t_stack *stack1, int nu);
int		*ft_check_move_stack_b(t_stack *stack_A, t_stack *stack_B);
void	ft_big_number(t_stack *stack1, t_stack *stack2);
int		ft_get_indexof_number(t_stack *stack1, int numb);
int		ft_git_next(t_stack *stack1, int num);
int		ft_gitmin(int *move);
void	ft_move_to_top_b(t_stack *stack1, int numb);
void	ft_sort(t_stack *stack1, t_stack *stack2);
void	ft_help_tosort(t_stack *stack1, t_stack *stack2, int push_count);
/*------------------ this function i'ts used for bonus part ------------------*/
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_next_str(char *r_str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_str(int fd, char *str);
char	*get_next_line(int fd);

#endif // !PUSHSWAP_H