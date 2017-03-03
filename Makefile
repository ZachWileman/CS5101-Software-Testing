pegtest:
	g++ -o pegtest Peg.cpp PegTest.cpp -lcppunit
boardtest:
	g++ -o boardtest Peg.cpp Board.cpp BoardTest.cpp -lcppunit

.PHONY: clean

clean:
	rm boardtest pegtest	
