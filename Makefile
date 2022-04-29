NAME_FT			=	ft_containers
NAME_STD		=	std_containers
SRCS			= 	main.cpp
OBJS			= 	$(SRCS:.cpp=.o)
SRCS_TESTS		=	tests/testStack.cpp \
					tests/testVector.cpp \
					# tests/testMap.cpp \
					# tests/testSet.cpp
OBJS_TESTS_FT	=	$(SRCS_TESTS:.cpp=_ft.o)
OBJS_TESTS_STD	=	$(SRCS_TESTS:.cpp=_std.o)

NAME_BONUS		=	ft_containers_bonus
SRCS_BONUS		= 	main_bonus.cpp
OBJS_BONUS		= 	$(SRCS_BONUS:.cpp=.o)

CFLAGS			= 	-Wall -Wextra -Werror
CC				= 	g++
USE_STD			=	USE_STD

%_std.o :		%.cpp
				$(CC) -c -g -I./tests -I./containers -I./utils $(CFLAGS) -D$(USE_STD) $< -o $@
%_ft.o :		%.cpp
				$(CC) -c -g -I./tests -I./containers -I./utils $(CFLAGS) $< -o $@
%.o :			%.cpp
				$(CC) -c -g -I./tests -I./containers -I./utils $(CFLAGS) $< -o $@

all:			$(NAME_FT) $(NAME_STD)
				mkdir outputs
				mkdir performances

$(NAME_FT):		$(OBJS) $(OBJS_TESTS_FT)
				$(CC) $(OBJS) $(OBJS_TESTS_FT) -o $(NAME_FT)

$(NAME_STD):	$(OBJS) $(OBJS_TESTS_STD)
				$(CC) $(OBJS) $(OBJS_TESTS_STD) -o $(NAME_STD)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
				rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_TESTS_FT) $(OBJS_TESTS_STD)

fclean:			clean
				rm -f $(NAME_FT) $(NAME_STD) $(NAME_BONUS)
				rm -rf outputs performances

re:				fclean all

.PHONY:			all clean fclean re $(NAME_FT) $(NAME_STD) bonus $(NAME_BONUS)