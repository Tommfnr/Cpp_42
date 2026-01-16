CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME    = DiamondTrap

SRC =   main.cpp \
		ScavTrap.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \

OBJ_DIR = build
OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEPS    = $(OBJ:.o=.d)

GREEN   = \033[32m
RED     = \033[31m
BLUE    = \033[34m
BOLD    = \033[1m
RESET   = \033[0m

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Program is ready!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files deleted.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Executable deleted.$(RESET)"

re: fclean all

-include $(DEPS)
