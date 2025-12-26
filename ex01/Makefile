NAME			= span
CXX				= c++
CXXFLGS			= -Wall -Wextra -Werror -std=c++98

INCS			= Span.hpp
SRCS			= Span.cpp main.cpp

OBJ_DIR			= obj

OBJS			= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLGS) $(OBJS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)	

$(OBJ_DIR)/%.o: %.cpp $(INCS) | $(OBJ_DIR)
	$(CXX) $(CXXFLGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

