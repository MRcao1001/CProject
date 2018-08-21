TARGET:=EPspace

OBJS:=CompanyMembers.o DataProcessing.o Display.o EnterPriseSpace.o EPHelper.o FileService.o Implement.o SmartInput.o 

$(TARGET):$(OBJS)
	g++ $(OBJS) -o $(TARGET) -Wall

%.o:%.cpp
	g++ -c $< -o $@ -Wall

clean:
	rm *.o

run:
	./EPspace
