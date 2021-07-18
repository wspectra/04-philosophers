NAME		= philo

DIR_S = ./src

DIR_O = ./obj

SOURCES		=  main.c utils.c parsing.c init.c

SRCS = $(addprefix $(DIR_S)/,${SOURCES})

OBJS = $(addprefix $(DIR_O)/,${SOURCES:.c=.o})

INCL		= includes/philo.h

CC			= gcc

RM			= rm -f

FLAGS		= -g
#-Wall -Wextra -Werror

all:	dir $(NAME) done

dir:
	@echo "\033[0;35m\b"
	mkdir -p obj
	@echo "\033[0;35m"
done:
	@echo "\n\033[0;32m|___Done___|"

$(NAME): $(OBJS)
		@echo "\033[0;35m"
		$(CC) $(OBJS) -o $(NAME)
		chmod 777 $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(INCL)
		@echo "\033[0;34m\b"
		 $(CC) $(FLAGS)  -c $< -o $@

clean:
		@echo "\033[0;33m\b"
		$(RM) $(OBJS)
		rm -rf $(DIR_O)

fclean: clean
		@echo "\033[0;31m"
		$(RM) $(NAME)

re:		fclean all

norm:
	@echo "\033[0;32mnorminette $(DIR_S)/*.c\033[0m"
	@norminette $(DIR_S)/*.c
	@echo "\033[0;32mnorminette includes/*.h\033[0m"
	@norminette includes/*.h

.PHONY:
		all, clean, fclean, re, dir, norm