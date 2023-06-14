/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:37:32 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:39:06 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function takes each node and frees in the end.
 */
void	free_stack(t_node **head1, t_node **head2)
{
	t_node	*temp;

	while ((*head1))
	{
		temp = *head1;
		*head1 = (*head1)->next;
		free(temp);
	}
	while ((*head2))
	{
		temp = *head2;
		*head2 = (*head2)->next;
		free(temp);
	}
}

/**
* This function asssigns the correct index to the numbers.
*/
static void	assign_index(t_node *head1)
{
	int		index;
	t_node	*outer;
	t_node	*inside;

	index = 0;
	outer = head1;
	inside = head1;
	while (outer != NULL)
	{
		while (inside != NULL)
		{
			if (outer->data > inside->data)
				index++;
			inside = inside->next;
		}
		outer->index = index;
		outer = outer->next;
		inside = head1;
		index = 0;
	}
}

/**
 * This Function decides what sorter we will use from the amount the elements
 * we are presented.
 */
static void	decide_the_sorter(t_node **head1, t_node **head2, int amount)
{
	if (check_if_stack_is_solved(*head1) == 1)
	{
		free_stack(head1, head2);
		exit(0);
	}
	if (amount < 3)
		solve_less_than_three(head1);
	if (amount == 3)
		solve_three_nbr(head1);
	if (amount > 3 && amount < 6)
		solve_five_nbr(head1, head2, amount);
	if (amount > 5)
	{
		assign_index(*head1);
		radix_sort(head1, head2);
	}
}

/* void print_stack_a(t_node *head)
{
	struct t_node *temp;

	temp = head;
	printf("----start_stack_a----\n");
	if (!head)
		printf("        Empty        \n");
	while (temp != NULL)
	{
		printf("element: %d ", temp->data);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
	printf("-------stack_a-------\n\n");
}

void print_stack_b(t_node *head)
{
	struct t_node *temp;

	temp = head;
	printf("----start_stack_b----\n");
	if (!head)
		printf("        Empty        \n");
	while (temp != NULL)
	{
		printf("element: %d", temp->data);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
	printf("-------stack_b-------\n\n");
} */

int	main(int argc, char **argv)
{
	int				*stack_a;
	t_node			*head1;
	t_node			*head2;

	if (argc < 2)
		exit(1);
	stack_a = main_checker(argc, argv);
	head1 = malloc(sizeof(t_node));
	head2 = malloc(sizeof(t_node));
	if (!head1 || !head2)
		exit(1);
	head2->data = 0;
	head2->index = -1;
	head2->next = NULL;
	head1 = c_full_stack(head1, stack_a, (argc - 2));
	decide_the_sorter(&head1, &head2, argc - 1);
	free_stack(&head1, &head2);
	return (0);
}
