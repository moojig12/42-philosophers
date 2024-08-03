CC = cc

NAME = philo

HEADER = incl

SRCDIR = srcs
OBJDIR = objs

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

FLAG = -Wall -Werror -Wextra -pthread -I$(HEADER) -g

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(OBJS) -o $(NAME) $(FLAG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

memcheck: all
	valgrind --leak-check=full ./philo 5 800 200 200