pegtest:
	g++ -o pegtest Peg.cpp PegTest.cpp -lcppunit

boardtest:
	g++ -o boardtest Peg.cpp Board.cpp BoardTest.cpp -lcppunit

main:
	g++ -o main PegJumpController.cpp PegJumpView.cpp Board.cpp Peg.cpp PegJumpModel.cpp

.PHONY: clean

clean:
	rm boardtest pegtest main 2>/dev/null || true	
