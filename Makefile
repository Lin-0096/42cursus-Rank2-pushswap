CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME := push_swap
BONUS_NAME := checker
RM := rm -f

SRC_DIR := src
INC_DIR := includes
LIBFT_DIR := libft
LIBFT  := $(LIBFT_DIR)/libft.a

INCLUDES := -I$(INC_DIR) -I$(LIBFT_DIR)
SRCS := $(filter-out $(SRC_DIR)/checker.c, $(wildcard $(SRC_DIR)/*.c))
OBJS := $(SRCS:.c=.o)
BONUS_SRCS := $(filter-out $(SRC_DIR)/push_swap.c, $(wildcard $(SRC_DIR)/*.c))
BONUS_OBJS := $(BONUS_SRCS:.c=.o)



all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

%.o: %.c
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@ make clean -C $(LIBFT_DIR)

fclean: clean
	@ $(RM) $(NAME) $(BONUS_NAME)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all


.PHONY: all clean fclean re bonus
