CC		?= gcc
RM		= rm -rf
MV		= mv
COV		= gcovr

ifeq ($(OS),Windows_NT)
TARGET		= librepublican_calendar.dll
else
TARGET		= librepublican_calendar.so
endif

BASEFLAGS	= -Wall -Wextra -Werror -Iinclude
ifneq ($(OS),Windows_NT)
BASEFLAGS += -fPIC
endif
CFLAGS		+= $(BASEFLAGS) -O2
LDFLAGS		+= -shared
COVFLAGS	= $(BASEFLAGS) --coverage -O0 -g
TESTFLAGS	= -lcmocka

SRC_DIR		= src
TEST_DIR	= test

SRCS		= time.c
OBJS		= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

test: $(TEST_DIR)/test_time.c
	$(CC) $(COVFLAGS) $(TESTFLAGS) -o $(TEST_DIR)/test_time.o $^
	./$(TEST_DIR)/test_time.o
	$(MV) *.g* $(TEST_DIR)

coverage: test
	$(COV) -r . --html --html-details -o $@.html
	$(COV) -r . -s

clean:
	$(RM) $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno coverage.html $(OBJS) *.html
	$(RM) $(TEST_DIR)/*.o

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all test coverage clean fclean re
