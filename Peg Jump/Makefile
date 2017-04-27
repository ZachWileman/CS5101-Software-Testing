
pegtest:
	g++ -o pegtest Peg.cpp PegTest.cpp -lcppunit

boardtest:
	g++ -o boardtest Peg.cpp Board.cpp BoardTest.cpp -lcppunit

modeltest:
	g++ -o modeltest Peg.cpp Board.cpp PegJumpModelTest.cpp PegJumpModel.cpp -lcppunit

testsAndRun:
	make pegtest
	make boardtest
	make modeltest
	./pegtest
	./boardtest
	./modeltest

main:
	g++ -o main PegJumpController.cpp PegJumpView.cpp PegJumpModel.cpp Board.cpp Peg.cpp

clean:
	rm boardtest pegtest modeltest main *.xml 2>/dev/null || true	
