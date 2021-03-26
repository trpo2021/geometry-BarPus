CC=g++
CFLAGS=-Wall -Wextra -Werror
GEOMETRY_SRC = src/geometry/
LIBGEOMETRY_SRC = src/libgeometry/

GEOMETRY_OBJ = obj/src/geometry/ 
LIBGEOMETRY_OBJ = obj/src/libgeometry/ 

GEOMETRY_BIN = bin/

$(GEOMETRY_BIN)geometry: $(GEOMETRY_OBJ)geometry.o $(LIBGEOMETRY_OBJ)libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^
$(GEOMETRY_OBJ)geometry.o: $(GEOMETRY_SRC)geometry.cpp 
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)libgeometry.a: $(LIBGEOMETRY_OBJ)CircleRadius.o $(LIBGEOMETRY_OBJ)isGoodCircle.o $(LIBGEOMETRY_OBJ)PerimeterArea.o
	ar rcs $@ $^
$(LIBGEOMETRY_OBJ)CircleRadius.o: $(LIBGEOMETRY_SRC)CircleRadius.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)isGoodCircle.o: $(LIBGEOMETRY_SRC)isGoodCircle.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBGEOMETRY_OBJ)PerimeterArea.o: $(LIBGEOMETRY_SRC)PerimeterArea.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
clean:
	rm -rf $(GEOMETRY_OBJ)*.o
	rm -rf $(LIBGEOMETRY_OBJ)*.o
	rm -rf $(GEOMETRY_OBJ)*.a
	rm -rf $(GEOMETRY_BIN)geometry
format:
	git ls-files *.{cpp,h} | xargs clang-format -i
	git add .
	git commit -m "Format code"