CC		?= gcc
RM		= rm -rf
MV		= mv
COV		= gcovr

ifeq ($(OS),Windows_NT)
TARGET		= librepublican_calendar.dll
else
TARGET		= librepublican_calendar.so
endif

BASEFLAGS	= -Wall -Wextra -Werror -Iinclude -std=c99
ifneq ($(OS),Windows_NT)
BASEFLAGS += -fPIC
endif
CFLAGS		+= $(BASEFLAGS) -O2
LDFLAGS		+= -shared
COVFLAGS	= $(BASEFLAGS) --coverage -O0 -g
TESTFLAGS	=

SRC_DIR		= src
TEST_DIR	= test

SRCS		= localtime.c \
		  roman.c \
		  utils.c \
		  asctime.c
OBJS		= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

test_localtime: $(TEST_DIR)/test_localtime.c
	$(CC) $(COVFLAGS) $(TESTFLAGS) -o $(TEST_DIR)/$@.o $^
	./$(TEST_DIR)/$@.o

test_roman: $(TEST_DIR)/test_roman.c $(SRC_DIR)/utils.c
	$(CC) $(COVFLAGS) $(TESTFLAGS) -o $(TEST_DIR)/$@.o $^
	./$(TEST_DIR)/$@.o

test: test_localtime test_roman
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

.PHONY: all test coverage clean fclean re test_time test_roman
