

NAME        = so_long
CC          = gcc
CFLAGS      = -Wall -Wextra  -Werror
RM          = rm -f
LIB_PATH	= ./libft
LIB_SRC_P	= ./$(LIB_PATH)/src/
LDFLAGS		= -L$(LIB_PATH) -lft
SRCS_PATH           = src/
PRINTF_PATH	=	ftprintf/
OBJS_PATH           = obj/
SRC         =	main.c

SRC_PRINT	=	ft_c_format.c ft_i_format.c ft_printf_itoa.c ft_s_format.c \
				ft_uitoa.c ft_flags.c ft_p_format.c ft_printf_utils.c \
				ft_safe_free.c ft_x_format.c ft_flags2.c ft_printf.c \
				ft_put_words.c ft_u_format.c

SRC_LIB		=	ft_atoi.c ft_lstadd_back.c ft_memchr.c ft_split.c \
				ft_strmapi.c ft_bzero.c ft_lstadd_front.c\
				ft_memcmp.c ft_strchr.c ft_strncmp.c ft_calloc.c \
				ft_lstclear.c ft_memcpy.c ft_strcmp.c ft_strnstr.c \
				ft_isalnum.c ft_lstdelone.c ft_memmove.c ft_strdup.c \
			   	ft_strrchr.c ft_isalpha.c ft_lstiter.c ft_memset.c ft_striteri.c \
				ft_strtrim.c ft_isascii.c ft_lstlast.c ft_putchar_fd.c \
				ft_strjoin.c ft_substr.c ft_isdigit.c ft_lstmap.c ft_putendl_fd.c \
				ft_strlcat.c ft_tolower.c ft_isprint.c ft_lstnew.c ft_putnbr_fd.c \
				ft_strlcpy.c ft_toupper.c ft_itoa.c ft_lstsize.c ft_putstr_fd.c \
				ft_strlen.c


SRCS        =	$(addprefix $(SRCS_PATH),$(SRC)) \
			  	$(addprefix $(PRINTF_PATH),$(SRC_PRINT))
OBJS        =	$(addprefix $(OBJS_PATH),$(SRC:.c=.o)) \
				$(addprefix $(OBJS_PATH),$(SRC_PRINT:.c=.o))
LIBS		=	$(addprefix $(LIB_SRC_P),$(SRC_LIB))
INCS        = -I ./include/


CYAN = \033[0;96m
GREEN = \033[0;92m
MAGENTA = \033[0;95m
BLUE = \033[0;94m



all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(BLUE)Compiling $< $(DEF_COLOR)"

$(OBJS_PATH)%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(MAGENTA)Compiling $< $(DEF_COLOR)"

$(LIB_PATH)/libft.a : $(LIBS)
	@$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIB_PATH)/libft.a
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)So Long compiled!"
	

clean:
	@$(RM) -r $(OBJS_PATH)
	@$(MAKE) clean -C $(LIB_PATH) 
	@echo "$(GREEN)so_long executable files cleaned!$(DEF_COLOR)"


fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)

re: fclean all
