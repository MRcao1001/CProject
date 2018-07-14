TARGET:=main
OBJS:=main.o test.o

$(TARGET):$(OBJS)
	gcc $(OBJS) -o $(TARGET)

%.o:%.c
	gcc -c $< -o $@

clean: 	#伪目标
	rm $(OBJS) $(TARGET)

                                 


