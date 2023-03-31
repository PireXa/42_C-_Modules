SRCS		=	main.cpp ClapTrap.cpp ScavTrap.cpp \

OBJS		=	$(addprefix objs/,$(SRCS:.cpp=.o))

CFLAGS		= 	-std=c++98 -Wall -Wextra -Werror

RM			=	rm -f

CC 			=	c++

NAME		=	ScavTrap

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
