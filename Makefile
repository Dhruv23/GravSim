CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = main.o Vector2.o Body.o Simulation.o Render.o

all: sim

sim: $(OBJS)
	$(CXX) $(CXXFLAGS) -o sim $(OBJS)

main.o: main.cpp Vector2.h Body.h Simulation.h Render.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Vector2.o: Vector2.cpp Vector2.h
	$(CXX) $(CXXFLAGS) -c Vector2.cpp

Body.o: Body.cpp Body.h Vector2.h
	$(CXX) $(CXXFLAGS) -c Body.cpp

Simulation.o: Simulation.cpp Simulation.h Body.h
	$(CXX) $(CXXFLAGS) -c Simulation.cpp

Render.o: Render.cpp Render.h Body.h
	$(CXX) $(CXXFLAGS) -c Render.cpp

# ====== TESTS ======

Vector2Test.o: Vector2Test.cpp Vector2.h
	$(CXX) $(CXXFLAGS) -c Vector2Test.cpp

BodyTest.o: BodyTest.cpp Body.h Vector2.h
	$(CXX) $(CXXFLAGS) -c BodyTest.cpp

SimulationTest.o: SimulationTest.cpp Simulation.h Body.h Vector2.h
	$(CXX) $(CXXFLAGS) -c SimulationTest.cpp

RenderTest.o: RenderTest.cpp Render.h Body.h Vector2.h
	$(CXX) $(CXXFLAGS) -c RenderTest.cpp

# Test executables

test_vector2: Vector2Test.o Vector2.o
	$(CXX) $(CXXFLAGS) -o test_vector2 Vector2Test.o Vector2.o

test_body: BodyTest.o Body.o Vector2.o
	$(CXX) $(CXXFLAGS) -o test_body BodyTest.o Body.o Vector2.o

test_simulation: SimulationTest.o Simulation.o Body.o Vector2.o
	$(CXX) $(CXXFLAGS) -o test_simulation SimulationTest.o Simulation.o Body.o Vector2.o

test_render: RenderTest.o Render.o Body.o Vector2.o
	$(CXX) $(CXXFLAGS) -o test_render RenderTest.o Render.o Body.o Vector2.o

# ===== CLEAN =====

clean:
	rm -f *.o sim test_vector2 test_body test_simulation test_render

clall: clean all
