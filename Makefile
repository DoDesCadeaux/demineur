NAME = demineur

CC = c++

INCLUDE_PATH = -I/opt/homebrew/Cellar/sfml/2.6.1/include 

LIB_PATH = -L/opt/homebrew/Cellar/sfml/2.6.1/lib 

CFLAGS = -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system 

YELLOW = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m
NO_COL = \033[0m

all:
	@$(CC) main.cpp $(INCLUDE_PATH) -o $(NAME) $(LIB_PATH) $(CFLAGS)
	@echo "$(YELLOW)Compiling: $(BLUE)$(NAME)$(NO_COL)"
clean:
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME) $(RED)Removed$(NO_COL)"
