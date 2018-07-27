/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:11:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 11:13:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix_ft.h>

t_matrix	*new_matrix(t_coor rows, t_coor cols)
{
	t_matrix *ret;
	int	ind;

	ind = 0;
	ret = (t_matrix *)ft_memalloc(sizeof(t_matrix));
	ret->rows = rows;
	ret->cols = cols;
	ret->cells = (float **)ft_memalloc(rows * sizeof(float *));
	while(ind < rows)
		ret->cells[ind++] = (float *)ft_memalloc(sizeof(float) * cols);
	return (ret);
}

void		del_matrix(t_matrix *mtr)
{
	int r;

	r = 0;
	while (r < mtr->rows)
		free(mtr->cells[r++]);
	free(mtr->cells);
	free(mtr);
}