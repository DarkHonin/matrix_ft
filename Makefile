LIBFT=libft
LIB_DIR=$(addprefix  ${CURDIR}/,$(LIBFT))
DEPS= $(addprefix  $(LIBFT)/,libft.a)

INCLUDES= -I "$(LIB_DIR)"
LIBS=-lft -L "$(LIB_DIR)"

OBJ=matrix.o

make: $(DEPS) $(OBJ)
	gcc testmain.c $(OBJ) $(INCLUDES) $(LIBS)

$(OBJ):
	gcc $*.c -c $(INCLUDES)

$(DEPS):
	make -C $(LIB_DIR) $(CMD)

clean:
	rm $(OBJ)