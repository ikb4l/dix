CC = gcc
CC_FLAGS = -Iinclude
SOURCES = $(shell find src/ -type f -name '*.c')
OBJECTS = $(SOURCES:.c=.o)
TARGET = dix

.PHONY: all clean

$(TARGET): $(OBJECTS)
	@echo LINK:: $(TARGET)
	@$(CC) $(CC_FLAGS) $(OBJECTS) -o $(TARGET)
	@echo DONE!

%.o: %.c
	@echo CC:: $<
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@echo CLEAN:: $(OBJECTS) $(TARGET)
	@rm $(OBJECTS) $(TARGET)

all: clean $(TARGET)

