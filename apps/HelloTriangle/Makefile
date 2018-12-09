CFLAGS = -std=c++17
#CFLAGS += -DNDEBUG

LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

.PHONY: test clean

HelloTriangle: main.cpp HelloTriangleApplication.h HelloTriangleApplication.cpp
	g++ $(CFLAGS) -o HelloTriangle main.cpp HelloTriangleApplication.cpp $(LDFLAGS)

test: HelloTriangle
	./HelloTriangle

clean:
	rm -f HelloTriangle
