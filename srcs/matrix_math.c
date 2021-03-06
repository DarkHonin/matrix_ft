/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:32:17 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/07 10:22:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_ft.h"

t_matrix	*matrix_prod(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*ret;
	t_coor		x;
	t_coor		y;

	matrix_valid_multiple(m1, m2);
	y = 0;
	ret = new_matrix(m1->rows, m2->cols);
	while (y < ret->rows)
	{
		x = 0;
		while (x < ret->cols)
		{
			ret->cells[y][x] = matrix_rc_prod(m1, m2, x, y);
			x++;
		}
		y++;
	}
	return (ret);
}

float		matrix_rc_prod(t_matrix *m1, t_matrix *m2, t_coor c, t_coor r)
{
	float	*row;
	float	**col;
	size_t		index;
	float	tot;	

	matrix_valid_multiple(m1, m2);
	tot = 0;
	index = 0;
	col = get_col(m2, c);
	row = get_row(m1, r);
	while (index < m1->cols)
	{
		tot += *col[index] * row[index];
		index++;
	}
	return (tot);
}

t_matrix	*matrix_dif(t_matrix *a, t_matrix *b)
{
	t_matrix	*ret;
	size_t		c;
	size_t		r;

	matrix_valid_arithmetic(a, b);
	ret = new_matrix(a->rows, a->cols);
	r = 0;
	while (r < ret->rows)
	{
		c = 0;
		while (c < ret->cols)
		{
			ret->cells[r][c] = a->cells[r][c] - b->cells[r][c];
			c++;
		}
		r++;
	}
	return (ret);
}