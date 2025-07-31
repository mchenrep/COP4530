CXX = g++              
CXXFLAGS = -Wall -g    
TARGET = proj1.x        
SRCS = proj1.cpp        
OBJS = $(SRCS:.cpp=.o)  

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
