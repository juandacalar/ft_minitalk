OBJ_DIR		=	obj
SRCS		=   ft_printf.c \
				extras/ft_write.c \
				extras/ft_hexlen.c \
				extras/ft_itoa.c \
				extras/ft_itox.c \
				extras/ft_strcpy.c \
				extras/ft_uitoa.c \
				extras/ft_uiptox.c \
				extras/ft_libft.c \
				ft_printf_args_char.c ft_printf_args_int.c \
				ft_printf_args_pointer.c \
				ft_printf_args_string.c ft_printf_args_unint.c \
				ft_printf_args_x.c
OBJS     	=   $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
NAME		=	libftprintf.a
INCS		=	ft_printf.h
LIBC		=	ar rc
RM			=	rm -rf
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/extras
	gcc -Wall -Wextra -Werror -c $< -o $@

all: ${NAME}

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c ${SRCS}

$(NAME): ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean: 
	${RM} $(OBJ_DIR) main.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
