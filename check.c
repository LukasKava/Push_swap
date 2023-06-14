/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:21:26 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 17:17:18 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Check int overflow
 */
static void	check_for_overflow(long b, int neg, int *arr)
{
	if (b > 2147483647 && neg == 1)
	{
		write(1, "ERROR: Exceeds INT_MAX\n", 24);
		free(arr);
		exit(1);
	}
	if (b > 2147483648 && neg == -1)
	{
		write(1, "ERROR: Exceeds INT_MIN\n", 24);
		free(arr);
		exit(1);
	}
}

/**
 * Function: ft_isdigit goes through the  command line arguments and
 * checks to see if there is not an integer. If it finds that one of the
 * elements is not an integer it prints the error and quits the program.
 */
static void	ft_isdigit(char **argv, int argc)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i <= argc)
	{
		if ((argv[i][x] == '-' || argv[i][x] == '+') &&
			(argv[i][x + 1] >= '0' && argv[i][x + 1] <= '9'))
			x++;
		while (argv[i][x] != '\0')
		{
			if ((argv[i][x] < '0' || argv[i][x] > '9') && argv[i][x] != '\0')
			{
				write(1, "ERROR: some of the arguments are not integers!\n", 48);
				exit(1);
			}
			x++;
		}
		x = 0;
		i++;
	}
}

/**
 * FUNCTION: check_duplicates goes through the integer array and checks for the
 * duplicates.
 * If it founds duplicates it prints the error message and !returns (1). If it
 * does not it returns (0).
 */
static int	check_duplicates(int len, int *arr)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	while (i < len)
	{
		while (x < len)
		{
			if (arr[x] == arr[i] && x < len)
			{
				write(1, "ERROR: there are duplicates!\n", 30);
				return (1);
			}
			x++;
		}
		i++;
		x = i + 1;
	}
	return (0);
}

/*---- Modified ft_atoi for a bigger range and to convert char to int ----*/

static int	ft_atoi(char *str, int *arr)
{
	int			i;
	long int	b;
	int			neg;

	i = 0;
	b = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' && str[i] != '\0')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		b = b * 10 + (str[i] - '0');
		i++;
	}
	check_for_overflow(b, neg, arr);
	return (neg * (int)b);
}

/*---- Main checker -------------------------------------------------------*/

int	*main_checker(int argc, char **argv)
{
	int	*arr;
	int	hold;
	int	i;

	i = 0;
	argc = argc - 1;
	ft_isdigit(argv, argc);
	arr = malloc(sizeof(int) * argc);
	while (i < argc)
	{
		hold = ft_atoi(argv[i + 1], arr);
		arr[i] = hold;
		i++;
	}
	if (check_duplicates(argc, arr) == 1)
	{
		free(arr);
		exit(1);
	}
	return (arr);
}
