/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dale <dale@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:29:19 by dale              #+#    #+#             */
/*   Updated: 2025/08/17 14:29:21 by dale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_tower(int row, int col, int **matrix, int size);

int	solve(int row, int col, int **matrix, int size)
{
	int	tower;

	if (row == size && col == size + 1)
		return (1);
	if (col == size + 1)
	{
		row++;
		col = 1;
	}
	tower = 1;
	while (tower <= size)
	{
		matrix[row][col] = tower;
		if (is_valid_tower(row, col, matrix, size))
		{
			if (solve(row, col + 1, matrix, size))
				return (1);
		}
		tower++;
	}
	matrix[row][col] = 0;
	return (0);
}
