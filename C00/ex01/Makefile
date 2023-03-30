SRCS		=	main.cpp phonebook.cpp contact.cpp is_string_digit.cpp\

OBJS		=	$(addprefix objs/,$(SRCS:.cpp=.o))

CFLAGS		= 	-g -std=c++98 -Wall -Wextra -Werror

CC			=	c++

RM			=	rm -f

NAME		=	phonebook

all:		$(NAME)

objs/%.o: srcs/%.cpp
			@mkdir -p objs
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:		fclean all
