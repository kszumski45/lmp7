a.out: indx.o skorowidz.o
	$(CC) $^

indx.o: skorowidz.h
skorowidz.o: skorowidz.h

