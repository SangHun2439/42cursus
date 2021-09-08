/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:54:11 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/08 12:18:22 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_select_swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	pivot = arr[start];
	left = start + 1;
	right = end;
	while (1)
	{
		while (left < end && pivot > arr[left])
			left++;
		while (right > start && pivot < arr[right])
			right--;
		if (left < right)
			quick_select_swap(arr, left, right);
		else
			break;
	}
	quick_select_swap(arr, right, start);
	return (right);
}

int	quick_select(int *arr, int start, int end, int k)
{
	int	pivot;

	pivot = partition(arr, start, end);
	if (k == pivot)
		return arr[pivot];
	else if (k < pivot)
		return (quick_select(arr, start, pivot - 1, k));
	else
		return (quick_select(arr, pivot + 1, end, k));
}

int	quick_select_deq(t_deque *deq, int start, int end, int k)
{
	int	*arr;
	int	idx;
	int	size;
	int	res;

	idx = 0;
	size = end - start + 1;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	while (idx < size)
	{
		arr[idx] = *(int *)ft_deqget_idx(deq, idx);
		idx++;
	}
	res = quick_select(arr, start, end, k);
	free(arr);
	return (res);
}
