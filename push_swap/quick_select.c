/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:54:11 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/06 16:28:25 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *arr, int a, int b)
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
			swap(arr, left, right);
		else
			break;
	}
	swap(arr, right, start);
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
