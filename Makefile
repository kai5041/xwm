PROJECT_NAME := xwm
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

CXX ?= g++
CXX_FLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
LD_FLAGS ?=

PLATFORM_NAME ?= $(shell uname -s | tr '[:upper:]' '[:lower:]')

ifeq ($(PLATFORM_NAME),Linux)
    include toolchains/linux.mk
endif

ifeq ($(PLATFORM_NAME),Darwin)
    include toolchains/macos.mk
endif

ifeq ($(PLATFORM_NAME),Windows)
    include toolchains/windows.mk
endif

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/$(PLATFORM_NAME)/%.o,$(SOURCES))
-include $(OBJECTS:.o=.d)

all: $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)/$(PLATFORM_NAME)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(LD_FLAGS)

$(BUILD_DIR)/$(PLATFORM_NAME)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)/$(PLATFORM_NAME)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/$(PLATFORM_NAME)

run: all
	./$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)
