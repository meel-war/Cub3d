NAME	= cub3d
SRC		= src/main.c src/map_init.c
OBJS	= $(SRC:.c=.o)
CC		= cc
LIBS 	= -lmlx -lXext -lX11 -lm
FLAGS	= -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

RESET		= \033[0m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo -n "$(BLUE)Compiling: ["
	@i=0; total=30; \
	while [ $$i -le $$total ]; do \
		percent=$$(( 100 * $$i / $$total )); \
		done=$$(( $$total - $$i )); \
		printf "\r$(BLUE)Compiling: ["; \
		printf "%0.s█" `seq 1 $$i`; \
		printf "%0.s " `seq 1 $$done`; \
		printf "] %3d%%" $$percent; \
		sleep 0.02; \
		i=`expr $$i + 1`; \
	done; \
	echo "$(RESET)"
	@echo ""
	@echo "$(MAGENTA)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(CYAN)    🎮  Cub3d compilation complete! 🎮    $(RESET)"
	@echo "$(MAGENTA)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo ""
	@echo "$(BLUE)👾 by meel-war & pribolzi 👾$(RESET)"

$(LIBFT):
	@make all -C libft > /dev/null
	@echo "\n$(GREEN)Libft compiled successfully! 📚\n"

%.o: %.c
	@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "$(YELLOW)[Compiling] $< 💾]$(RESET)"

clean:
	@rm -rf $(OBJS)
	@make clean -C libft > /dev/null
	@echo "$(YELLOW)[🧹] Object files cleaned.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft > /dev/null
	@echo "$(RED)[🔥] Executable and all cleaned.$(RESET)"

re: fclean all

v: $(NAME)
	@echo "$(BLUE)[🔍] Running Valgrind with args: $(ARGS)$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

.PHONY: all clean fclean re v