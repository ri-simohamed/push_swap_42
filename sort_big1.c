/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:03:38 by mrami             #+#    #+#             */
/*   Updated: 2023/04/11 00:55:44 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* 
loop in stack B, each number in stack B, 
calculate move to top + and clculate move of the next number to send in top
*/

int	*ft_check_move_stack_b(t_stack *stack_A, t_stack *stack_B)
{
	int	i;
	int	next_move;
	int	move;
	int	next_numb;
	int	*tab;

	tab = malloc((stack_B->counter) * sizeof(int));
	i = 0;
	while (i < stack_B->counter)
	{
		next_numb = ft_git_next(stack_A, stack_B->stack[i]);
		move = ft_calculate_move(stack_B, stack_B->stack[i]);
		next_move = ft_calculate_move(stack_A, next_numb);
		tab[i] = move + next_move;
		i++;
	}
	return (tab);
}

/* get min of tab than move */

int	ft_gitmin(int *move, int size)
{
	int	min_of_move;
	int	i;

	min_of_move = move[0];
	i = 0;
	while (i < size)
	{
		if (move[i] < min_of_move)
			min_of_move = move[i];
		i++;
	}
	return (min_of_move);
}

void	ft_move_to_top_b(t_stack *stack1, int number)
{
	int	i;
	int	index_number;

	i = 0;
	while (i < stack1->counter)
	{
		index_number = ft_get_indexof_number(stack1, number);
		if (index_number == 0)
			break ;
		else if (index_number < (stack1->counter / 2))
			ft_rotet_b(stack1);
		else if (index_number >= (stack1->counter / 2))
			ft_rotet_rev_b(stack1);
		i++;
	}
}

/* lasst sort */

void	ft_sort(t_stack *stack1, t_stack *stack2)
{
	int	*move;
	int	min;
	int	index;
	int	min_number;
	int	target;

	while (stack2->counter != 0)
	{
		move = ft_check_move_stack_b(stack1, stack2);
		min = ft_gitmin(move, stack2->counter);
		index = 0;
		while (move[index] != min)
			index++;
		target = stack2->stack[index];
		ft_move_to_top_b(stack2, target);
		ft_move_to_top(stack1, ft_git_next(stack1, target));
		ft_push(stack2, stack1);
		write(1, "pa\n", 3);
		free(move);
	}
	min_number = ft__get_min_of_stack(stack1);
	while (stack1->stack[0] != min_number)
		ft_rotet_rev_a(stack1);
}

/* help to sort five number */

void	ft_help_tosort(t_stack *stack1, t_stack *stack2, int push_count)
{
	while (push_count--)
	{
		ft_push(stack2, stack1);
		write(1, "pa\n", 3);
	}
}
