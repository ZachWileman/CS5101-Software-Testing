from tile import Tile
from board import Board

################################### HOW TO USE THIS FILE #########################################
# Pytest: Used for running unit tests                                                            #
# INSTALL: pytest (for me I installed it via command-line using: "pip3 install pytest")          #
# RUN: Just type "pytest" in the command-line while in the same directory as this file           #
#                                                                                                #
# Pytest-cov: Used for seeing how much code coverage there is                                    #
# INSTALL: pytest-cov (for me I installed it via command-line using: "pip3 install pytest-cov")  #
# RUN: Just type "py.test --cov-report term-missing --cov=./" in the command-line while in       #
#      the same directory as this file                                                           #
##################################################################################################

def test_create_board():
    rows = 10
    cols = 10

    created_board = Board()
    expected_board = [[Tile() for i in range(cols)] for j in range(rows)]

    for i in range(rows):
        for j in range(cols):
            assert created_board.board[i][j].status_code == expected_board[i][j].status_code
