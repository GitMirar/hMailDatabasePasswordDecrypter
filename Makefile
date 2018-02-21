default:
	g++ blowfish.cpp main.cpp -o decrypt

clean:
	rm -f decrypt

.PHONY: clean
