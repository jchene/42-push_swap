NAME		=	push_swap

SRCS		=	./srcs/*.c\

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall

SANFLAGS	=	-g -fsanitize=address

DEL			=	rm -f

OBJ			=	$(SRCS:.c=.o)

all:			$(NAME)

%.o:%.c
				$(CC) $(CFLAGS) -o $@ -c $<


$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

san:			$(OBJ)
				$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(OBJ)

fclean:			clean
				$(DEL) $(NAME)

re:				fclean all

.PHONY: 		all san clean fclean re