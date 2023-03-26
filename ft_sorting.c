/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:03:55 by mrami             #+#    #+#             */
/*   Updated: 2023/03/25 17:28:28 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* sort number last then thrie number */

void	ft_thriesorting(t_stack *stack1, int max_num, int min_num)
{
	if (max_num == stack1->stack[stack1->counter - 1]
		&& min_num == stack1->stack[1])
		ft_swap_to_a(stack1);
	if (max_num == stack1->stack[0]
		&& min_num == stack1->stack[stack1->counter - 1])
	{
		ft_swap_to_a(stack1);
		ft_rotet_rev_a(stack1);
	}
	if (max_num == stack1->stack[0] && min_num == stack1->stack[1])
		ft_rotet_rev_a(stack1);
	if (min_num == stack1->stack[0] && max_num == stack1->stack[1])
	{
		ft_swap_to_a(stack1);
		ft_rotet_a(stack1);
	}
	if (min_num == stack1->stack[stack1->counter - 1]
		&& max_num == stack1->stack[1])
		ft_rotet_rev_a(stack1);
}

/* sort an stack of 3 rondem number */

void	ft_sort_thri_num(t_stack *stack1)
{
	int	max_num;
	int	min_num;

	max_num = ft_get_max_of_stack(stack1);
	min_num = ft__get_min_of_stack(stack1);
	if (stack1->counter < 3)
	{
		if (min_num == stack1->stack[1])
			ft_swap_to_a(stack1);
	}
	else
		ft_thriesorting(stack1, max_num, min_num);
}

/* sort five randem number */

void	ft_sort_five(t_stack *stack1, t_stack *stack2)
{
	int	index_min;
	int	min_num;

	while (stack1->counter > 3)
	{
		min_num = ft__get_min_of_stack(stack1);
		index_min = ft_get_indexof_number(stack1, min_num);
		if (index_min == 0)
		{
			ft_push(stack1, stack2);
			write(1, "pb\n", 3);
		}
		else if (index_min == 1)
			ft_swap_to_a(stack1);
		else if (index_min >= stack1->counter / 2)
			ft_rotet_rev_a(stack1);
	}
	ft_sort_thri_num(stack1);
	int i = 0;
	while (i < 2)
	{
		ft_push(stack2, stack1);
		write(1, "pa\n", 3);
		i++;
	}
}

/* sort big number */

void	ft_big_number(t_stack *stack1, t_stack *stack2)
{
	int	len;

	len = stack1->counter;
	while (len > 5)
	{
		ft_push(stack1, stack2);
		write(1, "pb\n", 3);
		len--;
	}
	ft_sort_five(stack1, stack2);
	ft_check_move_stack_b(stack2, stack1);
}

/* get prev number */

int	ft_git_prev(t_stack *stack1, int num)
{
	int	i;
	int	j;
	int	*temp_stack;
	int	min_num;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (i < stack1->counter)
	{
		if (stack1->stack[i] < num)
			len++;
		i++;
	}
	temp_stack = malloc(len * sizeof(int));
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < stack1->counter)
	{
		if (stack1->stack[i] < num)
			temp_stack[j++] = stack1->stack[i];
		i++;
	}
	i = 0;
	min_num = temp_stack[0];
	while (i < len)
	{
		if (temp_stack[i] > min_num)
			min_num = temp_stack[i];
		i++;
	}
	return (min_num);
}

/* 79 93 56 13 81 49 70 26 31 60 19 59 5 35 97 33 42 63 22 62 89 96 1725 15 94 45 8 2 54 28 66 18 23 36 90 68 67 48 32 71 65 9 78 6 80 98 74 51 27 82 84 11 16 24 85 64 29 38 50 44 20 88 87 55 10 92 37 1 58 21 53 30 61 14 77 41 34 95 83 86 75 4 99 47 91 43 76 3 39 7 73 52 40 69 100 46 12 57 72 */