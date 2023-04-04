/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:03:38 by mrami             #+#    #+#             */
/*   Updated: 2023/04/04 22:12:54 by mrami            ###   ########.fr       */
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

	tab = malloc(stack_B->counter * sizeof(int));
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

int	ft_gitmin(int *move)
{
	int	min_of_move;
	int	i;

	min_of_move = move[0];
	i = 0;
	while (move[i])
	{
		if (move[i] < min_of_move)
			min_of_move = move[i];
		i++;
	}
	return (min_of_move);
}
