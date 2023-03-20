.PHONY = clean

CC = gcc

SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=%.o)

main: ${OBJS}
	${CC} ${OBJS} -o $@

%.o: %.c
	${CC} -c $<

clean:
	rm *.o
