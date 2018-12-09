CFLAGS = -std=c++17

LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

.PHONY: test clean

VulkanTest: main.cpp
	g++ $(CFLAGS) -o VulkanTest main.cpp $(LDFLAGS)

test: VulkanTest
	VK_LAYER_PATH=/etc/vulkan/explicit_layer.d ./VulkanTest

clean:
	rm -f VulkanTest
