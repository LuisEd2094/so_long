

NAME        = 	so_long
CFLAGS      = 	-Wall -Wextra  -Werror
RM          = 	rm -f
LIB_PATH	= 	./libft
LDFLAGS		= 	-L$(LIB_PATH) -lft -L./minilibx/minilibx-linux -lmlx_Linux -lXext -lX11
SRCS_PATH	= 	src/
OBJS_PATH	= 	obj/
DEPS_PATH	=	deps/
SRC         =	main.c errors.c parse_arguments.c
INCS        =	-I./include/ -I./libft/includes -I./minilibx/minilibx-linux


#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
LIGHT_GREEN = \033[1;92m

###

SRC			=	errors.c main.c parse_arguments.c parse_aux.c init_prg.c \
				frees_aux.c  play_game.c get_pos.c check_line.c\
				helpers_for_dev.c

OBJS        =	$(addprefix $(OBJS_PATH),$(SRC:.c=.o))

DEPS		=	$(addprefix $(DEPS_PATH),$(SRC:.c=.d))

LIBS		=	$(addprefix $(LIB_SRC_P),$(SRC_LIB))



all: make_lib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c | $(OBJS_PATH) $(DEPS_PATH)
	@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@
	@mv $(OBJS_PATH)$(notdir $(basename $<)).d $(DEPS_PATH)

$(OBJS_PATH):
	@echo "$(GREEN)Creating So long Obj Dir $(DEF_COLOR)"
	@mkdir -p $(OBJS_PATH)

$(DEPS_PATH):
	@echo "$(GREEN)Creating So long Deps Dir $(DEF_COLOR)"
	@mkdir -p $(DEPS_PATH)

make_lib: 
	@$(MAKE) -s -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIB_PATH)/libft.a
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) 
	@echo "$(GREEN)So Long compiled!$(DEF_COLOR)"
	

-include $(DEPS)

fclean_lib:
	@$(MAKE) fclean -s -C $(LIB_PATH)

clean_lib:
	@$(MAKE) clean -s -C $(LIB_PATH) 

clean: clean_lib clean_objects

fclean: fclean_lib clean_objects
	@$(RM) $(NAME)
	@echo "$(GREEN)So Long executable cleaned!$(DEF_COLOR)"

clean_objects:
	@echo "$(GREEN)So Long Objects and Dependencies cleaned!$(DEF_COLOR)"
	@$(RM) -r $(OBJS_PATH) $(DEPS_PATH)


re: fclean all 

.PHONY: all fclean clean fclean_lib clean_lib re 
