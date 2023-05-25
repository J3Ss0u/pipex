
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = pipex

PIPEX_DIR = .
FT_PRINTF_DIR = ../ft_printf
LIBFT_DIR = ../libft

SRCS = pipex.c \
		find_path.c \
		pipex_utiles.c \
		err_cmd.c

OBJS = $(SRCS:.c=.o)

DEPS = $(FT_PRINTF_DIR)/libftprintf.a $(LIBFT_DIR)/libft.a

INCLUDES = ../includes

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR) -I$(INCLUDES) -o $@ $^ $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR) -I$(INCLUDES) -c -o $@ $<

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
