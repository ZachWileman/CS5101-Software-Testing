CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= Peg.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

pegtest: PegTest.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ PegTest.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
