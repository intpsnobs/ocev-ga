CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -g

SRC :=  $(shell find src -name *.cpp)
SRCNAME = $(notdir $(SRC))
SRCOBJ = $(SRCNAME:%.cpp=%.o)


all: main
	@ echo "> done :)"
	@ echo "> run \"./bin/main path/config_file\""

main: $(SRCOBJ)
	@ echo "> Compiling: project"
	@g++ $(CXXFLAGS) -o bin/main $(addprefix obj/,$(SRCOBJ)) $(LDFLAGS)

$(SRCOBJ): $(SRC)
	@ echo "> Compiling: "$(@:%.o=%.cpp)
	@g++ $(CXXFLAGS) -o obj/$@ -c $(filter %/$(@:%.o=%.cpp), $^) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f obj/*.o bin/main
