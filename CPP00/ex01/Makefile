# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2024/02/10 17:43:25 by asuc             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGreen		=	$(shell printf "\033[1;32m")
RESET		=	$(shell printf "\033[0m")
BRed		=	$(shell printf "\033[1;31m")
BCyan		=	$(shell printf "\033[1;36m")
Green		=	$(shell printf "\033[0;32m")
Blue 		=	$(shell printf "\033[0;34m")
Bblue		=	$(shell printf "\033[1;34m")
NAME		=	PhoneBook
COMP		=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g
CACHE_DIR	:=	$(addprefix $(shell pwd)/, .cache)
MAKE		=	make --no-print-directory
AUTHORS		=	asuc
DEBUG		=	0
SRC			=	Contact.cpp \
				PhoneBook.cpp \
				main.cpp

OBJ_DIR = $(CACHE_DIR)/$(NAME)/obj
DEP_DIR = $(CACHE_DIR)/$(NAME)/dep

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEP = $(addprefix $(DEP_DIR)/,$(SRC:.cpp=.d))

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

_CURR = 0
_TOTAL = $(words $(OBJ))
_TOTAL_LEN = $(shell echo $(_TOTAL) | wc -c)
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	@if [ $(_CURR) -eq 1 ]; then \
		printf "$(Bblue)Compilation object files for $(NAME)$(RESET)\n"; \
	fi
	$(eval _CURR=$(shell echo $$(($(_CURR)+1))))
	$(eval _PERCENTAGE=$(shell echo $$(($(_CURR)*100/$(_TOTAL)))))
	@printf "\033[2K$(Green)[$(shell printf "% 3s" "$(_PERCENTAGE)")%%] $(shell printf "%*d/%d" $(_TOTAL_LEN) $(_CURR) $(_TOTAL)) Compiling $<\r"
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR)/$*)
	@$(COMP) $(CFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@


all :  $(NAME)

debug: CFLAGS += -gdwarf-4
debug: DEBUG = 1
debug: re

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)

$(NAME) : $(OBJ)
	@printf "$(Green)\033[2K[100%%] Linking $(NAME)\n"
	@$(COMP) $(CFLAGS) -o $(NAME) $(OBJ)
	@printf "$(BGreen)Compilation Final $(NAME)$(RESET)\n"

clean :
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@printf "$(BRed)Erase all obj and deb files$(RESET)\n"

fclean : clean
	@rm -rf $(NAME) $(CACHE_DIR)
	@printf "$(BRed)Erase $(NAME)$(RESET)\n"

re : fclean all

-include $(DEP)

.PHONY: all fclean clean re banner
