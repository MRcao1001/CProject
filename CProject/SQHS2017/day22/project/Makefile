TARGET:=admin

OBJS:=admin.o list.o public.o interfaceUI.o

$(TARGET):$(OBJS)
	gcc $(OBJS) -o $(TARGET) -Wall

%.o:%.c
	gcc -c $< -o $@ -Wall

clean:
	rm -fr $(TARGET) $(OBJS)


