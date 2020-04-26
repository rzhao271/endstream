CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -Wconversion -MMD
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := xtobmp
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)

OBJS     := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPS     := $(OBJS:%.o=%.d)

all: build $(APP_DIR)/$(TARGET)

$(APP_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) $^ -o $@

-include $(DEPS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<


.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(APP_DIR)/*
	-@rm -rvf $(OBJ_DIR)/*
