# macros

TARGET		:= fsmake
VERSION		:= 1.0.0
DEFINES		:= -D TARGET=\"$(TARGET)\" -D VERSION=\"$(VERSION)\"

# files

YFILES		:= $(wildcard *.y)

TABFILES	:= \
	$(YFILES:.y=.tab.c) \
	$(YFILES:.y=.tab.h)

YYFILES		:= lex.yy.c

CFILES		:= \
	$(wildcard *.c) \
	$(YFILES:.y=.tab.c) \
	$(YYFILES)

CPPFILES	:= $(wildcard *.cpp)

OBJECTS		:= \
	$(CFILES:.c=.o) \
	$(CPPFILES:.cpp=.o)

DEPS		:= $(OBJECTS:.o=.d)

.PHONY		:= all clean

# colours

PRE			:= \033[

NC			:= $(PRE)0m
GREEN		:= $(PRE)1;32m
YELLOW		:= $(PRE)1;33m
BLUE		:= $(PRE)1;36m
RED			:= $(PRE)1;31m

# tools

CC			:= gcc
CPP			:= g++
CFLAGS		:= $(DEFINES) -Wall -Wextra -Wpedantic -g -MMD -MP -c

FLEX		:= flex
FLEXFLAGS	:= 

BISON		:= bison
BISONFLAGS	:= -d

RM			:= rm
RMFLAGS		:= -f

# make

all: $(TARGET)
	@echo "$(GREEN)Build complete!$(NC)"

$(TARGET): $(OBJECTS)
	@echo "$(YELLOW)Making $@$(NC)"
	$(CPP) -o $(TARGET) $^

%.o: %.c
	@echo "$(BLUE)Making $@$(NC)"
	$(CC) $(CFLAGS) $<

%.o: %.cpp
	@echo "$(BLUE)Making $@$(NC)"
	$(CPP) $(CFLAGS) $<

lex.yy.c: lexer.l
	@echo "$(BLUE)Making $@$(NC)"
	$(FLEX) $(FLEXFLAGS) $<

grammar.tab.c grammar.tab.h: grammar.y
	@echo "$(BLUE)Making grammar.tab.c and grammar.tab.h$(NC)"
	$(BISON) $(BISONFLAGS) $<

clean:
	@echo "$(RED)Cleaning$(NC)"
	$(RM) $(RMFLAGS) $(TARGET) $(OBJECTS) $(DEPS) $(YYFILES) $(TABFILES)

# from generated dependency files

-include $(DEPS)
