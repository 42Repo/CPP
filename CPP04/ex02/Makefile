# Color Definitions
BGreen  := $(shell printf "\033[1;32m")
RESET   := $(shell printf "\033[0m")
BRed    := $(shell printf "\033[1;31m")
BCyan   := $(shell printf "\033[1;36m")
Green   := $(shell printf "\033[0;32m")
Blue    := $(shell printf "\033[0;34m")
BBlue   := $(shell printf "\033[1;34m")

# Project Settings
TARGET       := ex03
CXX          := c++
CXXFLAGS     := -Wall -Werror -Wextra -std=c++98
BUILD_DIR    := .build
OBJ_DIR      := $(BUILD_DIR)/obj
DEP_DIR      := $(BUILD_DIR)/dep

# Source and Object Files
SRCS         := main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS         := $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
DEPS         := $(addprefix $(DEP_DIR)/,$(SRCS:.cpp=.d))

# Default Target
all: $(TARGET)

# Debug Target
debug: CXXFLAGS += -gdwarf-4 -Wunused -Wconversion -Wfloat-equal -Wnon-virtual-dtor \
                   -Wpointer-arith -Wstrict-aliasing=2 -Wunreachable-code -Wnull-dereference \
                   -Wnonnull -Wpedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
                   -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations \
                   -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual \
                   -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
                   -Wstrict-overflow=5 -Wswitch-default -Wundef
debug: CXXFLAGS += $(shell if $(CXX) --version 2>&1 | grep -q 'clang'; \
                          then echo "-Weverything -Wno-suggest-destructor-override -Wno-suggest-override"; \
                          else echo "-Wlogical-op -Wstrict-null-sentinel"; fi)
debug: re

# Build Directories
$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

# Object File Compilation
CURR       = 0
TOTAL      = $(words $(OBJS))
TOTAL_LEN  = $(shell echo $(TOTAL) | wc -c)
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	@if [ $(CURR) -eq 1 ]; then \
		printf "$(BBlue)Compiling object files for $(TARGET)$(RESET)\n"; \
	fi
	$(eval CURR=$(shell echo $$(($(CURR)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURR)*100/$(TOTAL)))))
	@printf "\033[2K$(Green)[$(shell printf "% 3s" "$(PERCENTAGE)")%%] $(shell printf "%*d/%d" $(TOTAL_LEN) $(CURR) $(TOTAL)) Compiling $<\r"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

# Linking
$(TARGET): $(OBJS)
	@printf "$(Green)\033[2K[100%%] Linking $(TARGET)$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@printf "$(BGreen)Compilation of $(TARGET) completed.$(RESET)\n"

# Include Dependencies
-include $(DEPS)

# Clean Targets
clean:
	@rm -rf $(BUILD_DIR)
	@printf "$(BRed)Cleaned object and dependency files.$(RESET)\n"

fclean: clean
	@rm -f $(TARGET)
	@printf "$(BRed)Removed executable $(TARGET).$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re debug
