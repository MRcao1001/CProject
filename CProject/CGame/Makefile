TARGET:=game

OBJS:=game.o ui.o public.o

$(TARGET):$(OBJS)
	gcc $(OBJS) -o $(TARGET) -Wall -lcurses

%.o:%.c
	gcc -c $< -o $@ -Wall -lcurses

clean:
	rm -fr $(TARGET) $(OBJS)


