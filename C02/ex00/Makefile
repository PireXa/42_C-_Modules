SRCS		=	main.cpp Fixed.cpp \

OBJS		=	$(addprefix objs/,$(SRCS:.cpp=.o))

CFLAGS		=  -std=c++98 -Wall -Wextra -Werror

CC			=	c++

RM			=	rm -f

NAME		=	FixedPoint

all:		$(NAME)

objs/%.o: %.cpp
			@mkdir -p objs
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:		fclean all
