CXX=g++
CFLAGS=-Wall -Wextra -Werror -I src/ -I thirdparty/
GEOMETRY_SRC = src/geometry/
LIBGEOMETRY_SRC = src/libgeometry/

GEOMETRY_OBJ = obj/src/geometry/
LIBGEOMETRY_OBJ = obj/src/libgeometry/

GEOMETRY_BIN = bin/

SRC = src/

TEST = test/

TEST_OBJ = obj/test/

TEST_THIRDPARTY = test/thirdparty/

.PHONY: geometry

$(GEOMETRY_BIN)geometry: $(GEOMETRY_OBJ)main.o $(LIBGEOMETRY_OBJ)libgeometry.a
	$(CXX) $(CFLAGS) -o $@ $^
$(GEOMETRY_OBJ)main.o: $(GEOMETRY_SRC)main.cpp 
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)libgeometry.a: $(LIBGEOMETRY_OBJ)CircleRadius.o $(LIBGEOMETRY_OBJ)isGoodCircle.o $(LIBGEOMETRY_OBJ)PerimeterArea.o
	ar rcs $@ $^
$(LIBGEOMETRY_OBJ)CircleRadius.o: $(LIBGEOMETRY_SRC)CircleRadius.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)isGoodCircle.o: $(LIBGEOMETRY_SRC)isGoodCircle.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)PerimeterArea.o: $(LIBGEOMETRY_SRC)PerimeterArea.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^

.PHONY: test

test: $(GEOMETRY_BIN)test.exe

$(GEOMETRY_BIN)test.exe: $(TEST_OBJ)testmain.o $(TEST_OBJ)testlibgeometry.a
	$(CXX) $(CFLAGS) -o $@ $^
$(TEST_OBJ)testmain.o: $(TEST)testmain.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)testlibgeometry.a: $(TEST_OBJ)CircleRadius.o $(TEST_OBJ)isGoodCircle.o $(TEST_OBJ)PerimeterArea.o
	ar rcs $@ $^
$(TEST_OBJ)CircleRadius.o: $(LIBGEOMETRY_SRC)CircleRadius.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)isGoodCircle.o: $(LIBGEOMETRY_SRC)isGoodCircle.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)PerimeterArea.o: $(LIBGEOMETRY_SRC)PerimeterArea.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(GEOMETRY_OBJ)*.o
	rm -rf $(LIBGEOMETRY_OBJ)*.o
	rm -rf $(LIBGEOMETRY_OBJ)*.a
	rm -rf $(GEOMETRY_BIN)*.exe
	rm $(TEST_OBJ)*.o
	rm $(TEST_OBJ)*.a
	rm $(GEOMETRY_BIN)*.exe

.PHONY: format

format:
	git ls-files *.{cpp,h} | xargs clang-format -i
	git add .
	git commit -m "Format code"