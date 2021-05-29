file = ../../build/release/
CharServer = $(file)CharServer.o
CharService = $(file)CharService.o
libServer = $(file)libServer.so
main = ../../build/server/server

include  = ../../include/server
dbInclude = ../../include/server/dbModel
modelInclude = ../../include/server/ChatModel
thirdInclude = ../../thirdparty/

libModel = -lmuduo_net  -lmuduo_base -lpthread -lmysqlclient

all:$(CharServer) $(CharService) $(libServer) $(main)
$(CharServer):ChatServer.cpp
	g++ -c $^ -I $(include) -I $(thirdInclude) -I $(dbInclude) -I $(modelInclude)   $(libModel)  -o $@ -fPIC
$(CharService):ChatService.cpp
	g++ -c $^ -I $(include) -I $(thirdInclude) -I $(dbInclude) -I $(modelInclude)  $(libModel) -o $@ -fPIC
$(libServer):$(CharServer) $(CharService)
	g++ -shared -o $@ $^
$(main):main.cpp
	g++ $^ $(file)*.o  -I $(include) -I $(thirdInclude)  -I $(dbInclude) -I $(modelInclude)  $(libModel) -o $@

.PHONY:clean
clean:
	rm  $(libServer) $(main)
