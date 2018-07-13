#include "matrix_ft.h"

int main(void)
{
	t_matrix *mtr;
	float set[3] = {1, 2, 3};

	mtr = new_matrix(3, 3);
	print_matrix(mtr);
	set_row(mtr, 1, set);
	print_matrix(mtr);
	float *r0 = get_row(mtr, 0);
	float **c0 = get_col(mtr, 0);
	r0[0] = 20;
	r0[1] = 3;
	r0[2] = 10;
	print_matrix(mtr);
	*c0[0] = 15;
	*c0[1] = 6;
	*c0[2] = 9;
	print_matrix(mtr);
}