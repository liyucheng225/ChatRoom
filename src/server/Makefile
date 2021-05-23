file = ../../build/release/
CharServer = $(file)CharServer.o
CharService = $(file)CharService.o
libServer = $(file)libServer.so
main = ../../build/server/server
include  = ../../include/server 
thirdInclude = ../../thirdparty/
all:$(CharServer) $(CharService) $(libServer) $(main)
$(CharServer):ChatServer.cpp
	g++ -c $^ -I $(include) -I $(thirdInclude) -lmuduo_net -lmuduo_base -lpthread -o $@ -fPIC
$(CharService):ChatService.cpp
	g++ -c $^ -I $(include) -I $(thirdInclude) -lmuduo_net -lmuduo_base -lpthread -o $@ -fPIC
$(libServer):$(CharServer) $(CharService)
	g++ -shared -o $@ $^
$(main):main.cpp
	g++ $^ -I $(include) -I $(thirdInclude)  -lmuduo_net -lmuduo_base -lpthread  -L $(libServer) -libServer -o $@
.PHONY:clean
clean:
	rm $(CharServer) $(CharService) $(libServer)
