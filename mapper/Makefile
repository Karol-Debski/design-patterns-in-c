TARGET = demo


INCLUDE_DIR_PATH = $(CURDIR)/include

SOURCES_PATH = $(CURDIR)/src/mapper.c
SOURCES_PATH += $(CURDIR)/demo.c

OBJECT_FILES = $(SOURCES_PATH:.c=.o)

BUILD_DIR = $(CURDIR)/build/


CC = gcc
CFLAGS = -Wall -g -I$(INCLUDE_DIR_PATH)


all: $(TARGET)


$(TARGET): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "---- BUILD END ----"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT_FILES)
