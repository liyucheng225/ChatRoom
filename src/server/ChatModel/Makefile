INCLUDE = -I ../../../include/server/ChatModel
OBJ = ../../../build/release/
SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))
 
 
All:$(OBJS)
$(OBJS):%.o:%.cpp
%.o:%.cpp
	g++ -c $< $(INCLUDE)  -o $(OBJ)/$@	
clean:	
	rm -f $(OBJS)
	rm -f $(OBJ)