/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:21:56 by mrami             #+#    #+#             */
/*   Updated: 2023/03/25 17:24:39 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* get the first big number */

int	ft_git_next(t_stack *stack1, int num)
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
		if (stack1->stack[i] > num)
			len++;
		i++;
	}
	temp_stack = malloc(len * sizeof(int));
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < stack1->counter)
	{
		if (stack1->stack[i] > num)
			temp_stack[j++] = stack1->stack[i];
		i++;
	}
	i = 0;
	min_num = temp_stack[0];
	while (i < len)
	{
		if (temp_stack[i] < min_num)
			min_num = temp_stack[i];
		i++;
	}
	return (min_num);
}

/* get index of an number */

int	ft_get_indexof_number(t_stack *stack1, int numb)
{
	int	i;
	int	index;

	i = 0;
	while (i < stack1->counter)
	{
		if (stack1->stack[i] == numb)
			index = i;
		i++;
	}
	return (index);
}

/* move to top */

void	ft_move_to_top(t_stack *stack1, int number)
{
	int	i;
	int	index_number;

	i = 0;
	while (i < stack1->counter)
	{
		index_number = ft_get_indexof_number(stack1, number);
		if (index_number == 0)
			break;
		else if (index_number < (stack1->counter / 2))
			ft_rotet_a(stack1);
		else if (index_number >= (stack1->counter / 2))
			ft_rotet_rev_a(stack1);
		i++;
	}
}

/* calculete min move  */

int	ft_calculate_move(t_stack *stack1, int nu)
{
	int	nu_index;
	int	len;
	int	move;

	move = 0;
	len = stack1->counter;
	nu_index = ft_get_indexof_number(stack1, nu);
	if (nu_index < (len / 2))
		move = nu_index;
	else if (nu_index >= (len / 2))
		move = len - nu_index;
	return (move);
}

/* loop in stack B, each number in stack B, calculate move to top + and clculate move of next to send in top */

void	ft_check_move_stack_b(t_stack *stack2, t_stack *stack1)
{
	int	i;
	int	next_move;
	int	len;
	int	min_move;
	int	min_number;
	int	next_numb;

	len = stack2->counter;
	i = 0;
	while (i < len)
	{
		min_number = ft_get_max_of_stack(stack2);
		next_numb = ft_git_prev(stack2, min_number);
		min_move = ft_calculate_move(stack2, min_number);
		next_move = ft_calculate_move(stack2, next_numb);
		if (next_move < min_move)
		{
			ft_move_to_top(stack2, next_numb);
			ft_push(stack2, stack1);
			write(1, "pa\n", 3);
			ft_move_to_top(stack2, min_number);
			ft_push(stack2, stack1);
			write(1, "pa\n", 3);
			ft_swap_to_a(stack1);
			i++;
		}
		else
		{
			ft_move_to_top(stack2, min_number);
			ft_push(stack2, stack1);
			write(1, "pa\n", 3);
		}
		i++;
	}
}
