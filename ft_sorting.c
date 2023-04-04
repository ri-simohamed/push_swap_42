/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:03:55 by mrami             #+#    #+#             */
/*   Updated: 2023/04/04 22:30:24 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* sort number last then thrie number */

void ft_thriesorting(t_stack *stack1, int max_num, int min_num)
{
	if (max_num == stack1->stack[stack1->counter - 1] && min_num == stack1->stack[1])
		ft_swap_to_a(stack1);
	if (max_num == stack1->stack[0] && min_num == stack1->stack[stack1->counter - 1])
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
	if (min_num == stack1->stack[stack1->counter - 1] && max_num == stack1->stack[1])
		ft_rotet_rev_a(stack1);
}

/* sort an stack of 3 rondem number */

void ft_sort_thri_num(t_stack *stack1)
{
	int max_num;
	int min_num;

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

void ft_sort_five(t_stack *stack1, t_stack *stack2)
{
	int index_min;
	int min_num;
	int i;
	int push_count;

	push_count = 0;
	while (stack1->counter > 3)
	{
		min_num = ft__get_min_of_stack(stack1);
		index_min = ft_get_indexof_number(stack1, min_num);
		if (index_min == 0)
		{
			ft_push(stack1, stack2);
			write(1, "pb\n", 3);
			push_count++;
		}
		else if (index_min < stack1->counter / 2)
			ft_rotet_a(stack1);
		else if (index_min >= stack1->counter / 2)
			ft_rotet_rev_a(stack1);
	}
	ft_sort_thri_num(stack1);
	while (push_count)
	{
		ft_push(stack2, stack1);
		write(1, "pa\n", 3);
		push_count--;
	}
}

/* sort big number */

void ft_big_number(t_stack *stack1, t_stack *stack2)
{
	int len;
	int *move;
	int min;
	int i;
	int	index;
	int min_number;
	int target;
	
	len = stack1->counter;
	while (len > 5)
	{
		ft_push(stack1, stack2);
		write(1, "pb\n", 3);
		len--;
	}
	ft_sort_five(stack1, stack2);
	move = ft_check_move_stack_b(stack1, stack2);
	while (stack2->counter != 0)
	{
		min = move[0];
		i = 0;
		while (i < stack2->counter)
		{
			if (move[i] < min)
				min = move[i];
			i++;
		}
		index = 0;
		while (move[index] != min)
			index++;
		target = stack2->stack[index];
		ft_move_to_top(stack2, target);
		ft_move_to_top(stack1, ft_git_next(stack1, target));
		ft_push(stack2, stack1);
		write(1, "pa\n", 3);
	}
	min_number = ft__get_min_of_stack(stack1);
	while (stack1->stack[0] != min_number)
		ft_rotet_rev_a(stack1);
}

/* 79 93 56 13 81 49 70 26 31 60 19 59 5 35 97 33 42 63 22 62 89 96 1725 15 94 45 8 2 54 28 66 18 23 36 90 68 67 48 32 71 65 9 78 6 80 98 74 51 27 82 84 11 16 24 85 64 29 38 50 44 20 88 87 55 10 92 37 1 58 21 53 30 61 14 77 41 34 95 83 86 75 4 99 47 91 43 76 3 39 7 73 52 40 69 100 46 12 57 72 */