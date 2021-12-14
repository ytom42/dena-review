CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	connect4

SRCS	=	connect_four.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
