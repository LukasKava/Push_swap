/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:40:58 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 18:08:38 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	moving_index_front(t_node **head1, int index)
{
	while (index > 0)
	{
		ra(head1);
		index--;
	}
}

/**
 * It checks its position and brings it accordingly to front and 
 * then pushes it to stack_b;
 */
static void	not_last(t_node	**head1, t_node **head2, int index)
{
	int	element_count;

	element_count = count_elements(head1);
	if (index == element_count - 1)
		rra(head1);
	else if (index > element_count - 3 && element_count != 4)
	{
		rra(head1);
		rra(head1);
	}
	else
		moving_index_front(head1, index);
	push_b(head1, head2);
}

/**
 * This function is made to find min value and push it to stack_b.
 */
static void	push_min_to_stack_b(t_node	**head1, t_node **head2)
{
	t_node	*temp;
	int		index;
	int		min;

	temp = *head1;
	index = 0;
	min = find_min(head1);
	while (temp->data != min)
	{
		index++;
		temp = temp->next;
	}
	not_last(head1, head2, index);
}

/**
 * For solving 5 numbers I use a method where I find two min numbers and
 * push them to stack_b then I use a three number solver and push everything
 * back from stack_b.
 */
void	solve_five_nbr(t_node **head1, t_node **head2, int count)
{
	int	check;

	check = check_if_stack_is_solved(*head1);
	if (check == 1)
		return ;
	push_min_to_stack_b(head1, head2);
	if (count > 4)
		push_min_to_stack_b(head1, head2);
	solve_three_nbr(head1);
	while ((*head2)->next != NULL)
		push_a(head1, head2);
}
