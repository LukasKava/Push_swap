/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:31:20 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:24:14 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function takes care of proper end node creation.
 */
static t_node	*add_at_end(int number)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		exit(1);
	temp->data = number;
	temp->next = NULL;
	return (temp);
}

/**
 * Takes the first node and creates other nodes  and fills them up with
 * information
 */
static t_node	*to_stack_a(t_node *head1, int *stack_a, int len)
{
	t_node	*temp;
	int		i;

	temp = head1;
	i = 1;
	while (i <= len)
	{
		temp->next = add_at_end(stack_a[i]);
		temp = temp->next;
		i++;
	}
	return (head1);
}

/**
 * This function is responsible for creating a stack.
 * FIRST: it takes the head node assigns it a first number from the array
 *		  and sets the next pointer to zero.
 * SECOND: it uses the function (to_stack_a) which takes care of adding the
 * 		   other nodes on the excisting one. 
 */
t_node	*c_full_stack(t_node *head1, int *stack_a, int len)
{
	head1->data = stack_a[0];
	head1->next = NULL;
	head1 = to_stack_a(head1, stack_a, len);
	free(stack_a);
	return (head1);
}
