NAME_TEST = 	ut.out

NAME = 		ls

SRCS =		src/tri.c		\
		src/mini_ls.c

SRCS_TEST =   	test/tri.c

OBJS =	$(SRCS:.c=.o)

OBJS_TEST = $(SRCS_TEST:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=	-L../libstu -lstu

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME) $(NAME_TEST)

$(NAME): $(OBJS) src/main.o
	$(MAKE) -C ../libstu
	$(CC) -o $(NAME) $(OBJS) src/main.o $(LDFLAGS)

$(NAME_TEST): $(OBJS) $(OBJS_TEST)
	$(MAKE) -C ../libstu
	$(CC) -o $(NAME_TEST) $(OBJS) $(OBJS_TEST) $(LDFLAGS) -lcriterion

clean:
	$(MAKE) -C ../libstu clean
	@$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	$(MAKE) -C ../libstu fclean
	@$(RM) $(NAME) $(NAME_TEST)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
