PURPLE = \033[38;5;129m
GREEN = \033[38;5;82m
DEFAULT = \x1b[0m

NAME = MagasinSportif

SRC = main.cpp fournisseur.cpp magasin.cpp command.cpp dispo.cpp compFournisseur.cpp alert.cpp Personnel.cpp

SRCS = $(addprefix src/, $(SRC))

FLAGS = -std=c++11 -Wall -Wextra -Werror

all :  $(NAME)

$(NAME) :
	@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

clean :
	@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

re : clean all
