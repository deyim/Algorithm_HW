CC = g++
TARGET = sort.out
OBJECTS = main.o heap_sort.o insertion_sort.o qsort.o quick_sort.o quick_sort_opt.o selection_rec.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm *.o sort.out
