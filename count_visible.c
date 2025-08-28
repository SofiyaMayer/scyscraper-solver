/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_visible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dale <dale@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:41:39 by dale              #+#    #+#             */
/*   Updated: 2025/08/17 14:41:41 by dale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_visible(int *arr, int size)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	if (arr[0] != 0)
		count = 1;
	i = 0;
	j = 1;
	while (i < size && j < size)
	{
		if (arr[j] > arr[i])
		{
			count++;
			i = j;
		}
		j++;
	}
	free(arr);
	return (count);
}
