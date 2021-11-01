NAME		=	ministack

SRCS		=	../srcs/linknum.c\
				../srcs/linksort.c\
				../srcs/linkact.c\
				../srcs/linkelem.c\
				../srcs/linkinfo.c\
				../srcs/parsing.c\
				../srcs/strlib.c\
				../srcs/debug.c\
				../srcs/memory.c\
				../srcs/static.c\
				../srcs/chunks.c\
				../srcs/rotate.c\
				../srcs/rev_rotate.c\
				../srcs/push.c\
				../srcs/swap.c\
				./main.c\

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall -g

SANFLAGS	=	-fsanitize=address

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