NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putunsigned.c \
		ft_putx.c \

OBJS = $(SRCS:.c=.o) 

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CC_FLAGS) -c $<

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re : fclean all 

