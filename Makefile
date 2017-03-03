pegtest:
	g++ -o pegtest Peg.cpp PegTest.cpp -lcppunit

boardtest:
	g++ -o boardtest Peg.cpp Board.cpp BoardTest.cpp -lcppunit

main:
	g++ PegJumpController.cpp PegJumpView.cpp

.PHONY: clean

clean:
	rm boardtest pegtest	
