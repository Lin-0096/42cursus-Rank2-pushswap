CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME := push_swap
RM := rm -f

SRC_DIR := src
INC_DIR := includes
LIBFT_DIR := libft
LIBFT  := $(LIBFT_DIR)/libft.a

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)
INCLUDES := -I$(INC_DIR) -I$(LIBFT_DIR)


all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@ make clean -C $(LIBFT_DIR)

fclean: clean
	@ $(RM) $(NAME)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all


.PHONY: all clean fclean re
