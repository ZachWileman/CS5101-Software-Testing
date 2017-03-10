
pegtest:
	g++ -o pegtest Peg.cpp PegTest.cpp -lcppunit

boardtest:
	g++ -o boardtest Peg.cpp Board.cpp BoardTest.cpp -lcppunit

modeltest:
	g++ -o modeltest Peg.cpp Board.cpp PegJumpModelTest.cpp PegJumpModel.cpp -lcppunit

main:
	g++ -o main PegJumpController.cpp PegJumpView.cpp PegJumpModel.cpp Board.cpp Peg.cpp

.PHONY: clean

clean:
	rm boardtest pegtest main modeltest 2>/dev/null || true	
