SRCS	=	main.c \
				utils/check_death.c \
				utils/handle_forks.c \
				utils/philo_routine.c \
				utils/philo_start.c \
				utils/utils.c \
				utils/atoi.c \
			
OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread -I includes -g #-fsanitize=thread

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@


clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re