CXX=g++
CXXFLAGS=--std=c++11 -W -Wall -O3 -DNDEBUG

SRCS=Solver.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
LIB_OBJS=$(OBJS) lib.cpp

.PHONY: none
none:
	@echo "Run make windows, mac, linux to build platform-specific DLLs"; \
	    exit 1

.PHONY: mac
mac: $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -dynamiclib -o libconnect4.dylib $(LIB_OBJS)

c4solver:$(OBJS) main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o c4solver main.o $(OBJS) $(LDLIBS)

generator: generator.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o generator generator.o $(LDLIBS)

.depend: $(SRCS)
	$(CXX) $(CXXFLAGS) -MM $^ > ./.depend

-include .depend

clean:
	rm -f *.o *.dll *.dylib *.so .depend c4solver generator


