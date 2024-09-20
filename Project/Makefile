NAME        := pipex

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
SRC_DIR     := srcs
OBJ_DIR     := obj
LIBFT_DIR   := srcs/libft
INC_DIR     := includes

# Regular source files
SRCS        := \
			main.c \
			error/error_pipex.c \
			setup/pipex_setup.c \
			free_memory/free_pipex.c \
			command/command_execution.c \
			command/command_validation.c

# Set the source and object paths
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT       := $(LIBFT_DIR)/libft.a

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I $(INC_DIR) -I $(LIBFT_DIR)

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

RED			= \033[91;1m
GREEN		= \033[92;1m
YELLOW		= \033[93;1m
BLUE		= \033[94;1m
PINK		= \033[95;1m
CLEAR		= \033[0m

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling pipex.$(CLEAR)"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	$(info CREATED $(NAME))


# Rule for compiling regular source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(BLUE)Cleaning compiled files.$(CLEAR)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)Cleaning binary files.$(CLEAR)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean re all bonus
.SILENT:
