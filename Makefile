NAME		= philo

DIR_S = ./src

DIR_O = ./obj

SOURCES		=  main.c utils.c parsing.c

SRCS = $(addprefix $(DIR_S)/,${SOURCES})

OBJS = $(addprefix $(DIR_O)/,${SOURCES:.c=.o})

INCL		= includes/philo.h

CC			= gcc

RM			= rm -f

FLAGS		= -g
#-Wall -Wextra -Werror

all:	dir $(NAME)

dir:
	@echo "\033[0;32m"
	mkdir -p obj
$(NAME): $(OBJS)
		@echo "\033[0;35m"
		$(CC) $(OBJS) -o $(NAME)
		chmod 777 $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(INCL)
		 $(CC) $(FLAGS)  -c $< -o $@

clean:
		$(RM) $(OBJS)
		make clean -C ./libft/
		make clean -C ./mlx/

fclean: clean
		$(RM) $(NAME)
		$(RM) libmlx.dylib
		$(RM) ./mlx/libmlx.dylib
		make fclean -C ./libft/

re:		fclean all

norm:
	@echo "\033[0;32mnorminette $(DIR_S)/*.c\033[0m"
	@norminette $(DIR_S)/*.c
	@echo "\033[0;32mnorminette includes/*.h\033[0m"
	@norminette includes/*.h

.PHONY:
		all, clean, fclean, re