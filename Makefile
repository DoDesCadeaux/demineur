NAME = demineur
CC = g++
SRCS = main.cpp Demineur.cpp Square.cpp 
OBJS = $(SRCS:.cpp=.o)

INCLUDE_PATH = -I/opt/homebrew/Cellar/sfml/2.6.1/include
LIB_PATH = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
YELLOW = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m
NO_COL = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LIB_PATH) $(CFLAGS)
	@echo "$(YELLOW)Linking: $(BLUE)$(NAME)$(NO_COL)"

%.o: %.cpp
	@$(CC) -c $< $(INCLUDE_PATH) -o $@ -std=c++11
	@echo "$(YELLOW)Compiling: $(BLUE)$<$(NO_COL)"

clean:
	@$(RM) $(NAME) $(OBJS)
	@echo "$(BLUE)$(NAME) $(RED)and object files Removed$(NO_COL)"

re: clean all
