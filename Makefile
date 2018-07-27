NAME=libmatrix.a
LIB_CFG=../libs.mk
include ../gen.mk
export NAME

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"