
all:	lib	

lib:	solution.h solution.c
	gcc solution.c -fPIC -shared -o libsolution.so

clean:
	-rm main libsolution.so 2> /dev/null

