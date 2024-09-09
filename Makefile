clean:
	rm -rf observer

observer: observer.c
	gcc observer.c -o observer

