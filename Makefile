INCLUDE := -I./ 
SRC_COMM =	muduo/base/Thread.cc \
			muduo/base/Timestamp.cc \
			muduo/base/FileUtil.cc \
			muduo/base/ProcessInfo.cc \
			muduo/base/LogStream.cc \
			muduo/base/LogFile.cc \
 			muduo/base/Logging.cc \
 			muduo/base/Exception.cc \
			muduo/net/EventLoop.cpp \
			muduo/net/test/testEventLoop.cpp


OBJ_COMM = $(SRC_COMM:.cpp=.o)

#LIBS = ../lib/libmuduo_base.a ../lib/libmuduo_net.a

.SUFFIXES: .o .cpp
.cpp.o:
	g++ $(INCLUDE) -g -c -o $@ $<

PROGRAM = test
all: test
        
test: $(OBJ_COMM)  
	#g++ -o $@ $(INCLUDE) $(OBJ_COMM) $(LIBS) -lpthread -lrt 
	g++ -o $@ $(INCLUDE) $(OBJ_COMM)  -lpthread -lrt 
	
clean: 
	rm -f *.o
