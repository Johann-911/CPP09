CPP = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = ./btc

SRCS = main.cpp BitcoinExchange.cpp
OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp 
	@mkdir -p $(OBJS_DIR)
	$(CPP) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean reCPP = c++
