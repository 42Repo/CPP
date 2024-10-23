# Color Definitions
BGreen  := $(shell printf "\033[1;32m")
RESET   := $(shell printf "\033[0m")
BRed    := $(shell printf "\033[1;31m")
BCyan   := $(shell printf "\033[1;36m")
Green   := $(shell printf "\033[0;32m")
Blue    := $(shell printf "\033[0;34m")
BBlue   := $(shell printf "\033[1;34m")

# Project Settings
NAME   		:= ex01
COMPILER	:= c++
CPPFLAGS	:= -Wall -Wextra
CACHE_DIR	:= $(shell pwd)/.cache
OBJ_DIR		:= $(CACHE_DIR)/$(NAME)/obj
DEP_DIR		:= $(CACHE_DIR)/$(NAME)/dep

# Source and Object Files
SRC     := testMain.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ     := $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEP     := $(addprefix $(DEP_DIR)/,$(SRC:.cpp=.d))

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

all :  $(NAME)

debug: CPPFLAGS += -gdwarf-4 -Wunused -Wconversion -Wfloat-equal -Wnon-virtual-dtor -Wpointer-arith -Wstrict-aliasing=2 -Wunreachable-code -Wnull-dereference -Wnonnull -Wpedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef
debug: CPPFLAGS += $(shell if $(COMPILER) --version 2>&1 | grep -q 'clang'; \
                      then echo "-Weverything -Wno-suggest-destructor-override -Wno-suggest-override -Wno-unsafe-buffer-usage"; \
                      else echo "-Wlogical-op -Wstrict-null-sentinel"; fi)
debug: re

# Directory Creation
$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)


# Object File Compilation
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
	@$(COMPILER) $(CPPFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

# Linking
$(NAME) : $(OBJ)
	@printf "$(Green)\033[2K[100%%] Linking $(NAME)\n"
	@$(COMPILER) -lgtest -lgtest_main -lpthread $(CFLAGS) -o $(NAME) $(OBJ)
	@printf "$(BGreen)Compilation Final $(NAME)$(RESET)\n"

# Clean Targets
clean :
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@printf "$(BRed)Erase all obj and deb files$(RESET)\n"

fclean : clean
	@rm -rf $(NAME) $(CACHE_DIR)
	@printf "$(BRed)Erase $(NAME)$(RESET)\n"

re : fclean all

-include $(DEP)

.PHONY: all fclean clean re debug
