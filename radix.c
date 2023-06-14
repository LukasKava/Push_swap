/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:23:52 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:37:32 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/**
 * Function to find a maximum_bits it shifts the bits to right
 * until the number is is equal to 0 and it then returs the the amount of bits.
 */
static int	maximum_bits(int max_nbr)
{
	int	max_amount_of_bits;

	max_amount_of_bits = 0;
	while ((max_nbr >> max_amount_of_bits) != 0)
		max_amount_of_bits++;
	return (max_amount_of_bits);
}

/**
 * O(n+k) it is not optimal for small data sets.
 * For our purpose like 500 numbers quick_sort and merge_sort are better
 * options. Radix is good for bigger data sets.
 */
void	radix_sort(t_node **head1, t_node	**head2)
{
	int	i;
	int	x;
	int	elements;
	int	max_amount_of_bits;

	i = 0;
	x = 0;
	elements = count_elements(head1);
	max_amount_of_bits = maximum_bits(elements);
	while (x < max_amount_of_bits)
	{
		while (i < elements)
		{
			if ((((*head1)->index >> x) & 1) == 1)
				ra(head1);
			else
				push_b(head1, head2);
			i++;
		}
		while ((*head2)->next != NULL)
			push_a(head1, head2);
		i = 0;
		x++;
	}
}
