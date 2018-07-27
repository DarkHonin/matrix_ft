/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 23:55:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 11:11:40 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_ft.h"

void		set_cell(t_matrix *mtr, t_coor r, t_coor c, float p)
{
	mtr->cells[r][c] = p;
}

float		*get_row(t_matrix *mtr, t_coor r)
{
	return (mtr->cells[r]);
}

float		**get_col(t_matrix *mtr, t_coor c)
{
	float **ret;
	t_coor in;

	in = 0;
	ret = ft_memalloc(sizeof(float) * mtr->cols);
	while (in < mtr->cols)
	{
		ret[in] = &(mtr->cells[in][c]);
		in++;
	}
	return (ret);
}

void		print_matrix(t_matrix *mtr)
{
	size_t r;
	size_t c;

	ft_putstr("Matrix dimention: [");
	ft_putnbr(mtr->rows);
	ft_putstr(", ");
	ft_putnbr(mtr->cols);
	ft_putendl("]");
	r = 0;
	c = 0;
	while (r < mtr->rows)
	{
		c = 0;
		ft_putchar('[');
		while (c < mtr->cols)
		{
			ft_putnbr(mtr->cells[r][c++]);
			if (c != mtr->cols)
				ft_putstr(", ");
		}
		ft_putendl("]");
		r++;
	}
}