/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:09:04 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:26:03 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rb (rotate b): Shift up all elements of stack_b by 1.
 * The first element becomes the last one.
 */
void	rb(t_node **head2)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*temp;

	first_element = *head2;
	second_element = (*head2)->next;
	temp = *head2;
	*head2 = second_element;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_element;
	temp->next->next = NULL;
	write(1, "rb\n", 3);
}

/**
 * rr does ra and rb at the same time.
 */
void	rotate_both(t_node **head1, t_node **head2)
{
	ra(head1);
	rb(head2);
	write(1, "rr\n", 3);
}

/***
 * rra (reverse rotate a): Shift down all elements of stack_a by 1.
 * The last element will become the first one.
 */
void	rra(t_node **head1)
{
	t_node	*last_node;
	t_node	*before_last;
	t_node	*first_node;

	first_node = *head1;
	before_last = *head1;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last_node = before_last->next;
	before_last->next = NULL;
	*head1 = last_node;
	(*head1)->next = first_node;
	write(1, "rra\n", 4);
}

/***
 * rrb (reverse rotate b): Shift down all elements of stack_b by 1.
 * The last element will become the first one.
 */
void	rrb(t_node **head2)
{
	t_node	*last_node;
	t_node	*before_last;
	t_node	*first_node;

	first_node = *head2;
	before_last = *head2;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last_node = before_last->next;
	before_last->next = NULL;
	*head2 = last_node;
	(*head2)->next = first_node;
	write(1, "rrb\n", 4);
}

/**
 *  rrr does both rra and rrb
 */
void	rrr_both(t_node **head1, t_node **head2)
{
	rra(head1);
	rrb(head2);
	write(1, "rrr\n", 4);
}
