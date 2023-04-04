/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:21:56 by mrami             #+#    #+#             */
/*   Updated: 2023/03/31 17:41:16 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

int	ft_lenght_next(t_stack *stack1, int number)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < stack1->counter)
	{
		if (stack1->stack[i] > number)
			len++;
		i++;
	}
	return (len);
}

/* get the first big number */

int	ft_git_next(t_stack *stack1, int num)
{
	int	i;
	int	j;
	int	*temp_stack;
	int	min_num;

	i = -1;
	j = 0;
	if (ft_lenght_next(stack1, num) == 0)
		return ft__get_min_of_stack(stack1);
	temp_stack = malloc(ft_lenght_next(stack1, num) * sizeof(int));
	if (!temp_stack)
		return (0);
	i = -1;
	while (++i < stack1->counter)
	{
		if (stack1->stack[i] > num)
			temp_stack[j++] = stack1->stack[i];
	}
	i = -1;
	min_num = temp_stack[0];
	while (++i < ft_lenght_next(stack1, num))
	{
		if (temp_stack[i] < min_num)
			min_num = temp_stack[i];
	}
	return (min_num);
}

/* get index of an number */

int	ft_get_indexof_number(t_stack *stack1, int numb)
{
	int	i;
	int	index = 0;
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
			break ;
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
