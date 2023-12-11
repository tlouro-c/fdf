/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:22:02 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/23 02:54:58 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *array, int low, int high)
{
	int	pivot_index;
	int	pivot_value;
	int	i;
	int	j;

	pivot_index = ft_rand() % (high - low + 1) + low;
	pivot_value = array[pivot_index];
	ft_swap(&array[pivot_index], &array[high]);
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot_value)
		{
			if (i != j)
				ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[high]);
	return (i);
}

static void	ft_quick_sort_recursive(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		ft_quick_sort_recursive(array, low, pivot - 1);
		ft_quick_sort_recursive(array, pivot + 1, high);
	}
}

void	ft_quick_sort(int *array, int size)
{
	ft_quick_sort_recursive(array, 0, size - 1);
}
