PROJECT_NAME := xwm
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

CXX ?= g++
CXX_FLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
LD_FLAGS ?=

RELEASE_FLAGS ?= -O3 -DNDEBUG -static-libstdc++ -static-libgcc

PLATFORM_NAME ?= linux-x32_64

include toolchains/$(PLATFORM_NAME).mk

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/$(PLATFORM_NAME)/%.o,$(SOURCES))
-include $(OBJECTS:.o=.d)

# Default build (debug)
all: CXX_FLAGS += -g
all: $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

# Release build
release: CXX_FLAGS += $(RELEASE_FLAGS)
release: clean $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)/$(PLATFORM_NAME)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(LD_FLAGS)

$(BUILD_DIR)/$(PLATFORM_NAME)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)/$(PLATFORM_NAME)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)
