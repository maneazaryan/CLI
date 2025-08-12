CC= g++
CFLAGS=-Iinc
OBJ= obj/base.o obj/window.o obj/button.o obj/text.o obj/command.o  obj/table.o obj/manage.o
obj/%.o:src/%.cpp inc/%.h
	$(CC) $(CFLAGS) -c $< -o $@

bin/main.exe: src/main.cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean 

clean:
	rm -f obj/*.o bin/*.exe
