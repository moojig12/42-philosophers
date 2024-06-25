CC = cc

NAME = philo

HEADER = incl

SRCDIR = srcs
OBJDIR = objs

SRCS = $(SRCDIR)/main.c $(SRCDIR)/philo_utils.c $(SRCDIR)/check.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

FLAG = -Wall -Werror -Wextra -pthread -I$(HEADER)

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