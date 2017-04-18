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
    expected_board = {
        0: [ Tile(0,0), Tile(0,1), Tile(0,2), Tile(0,3), Tile(0,4), Tile(0,5), Tile(0,6), Tile(0,7), Tile(0,8), Tile(0,9) ],
        1: [ Tile(1,0), Tile(1,1), Tile(1,2), Tile(1,3), Tile(1,4), Tile(1,5), Tile(1,6), Tile(1,7), Tile(1,8), Tile(1,9) ],
        2: [ Tile(2,0), Tile(2,1), Tile(2,2), Tile(2,3), Tile(2,4), Tile(2,5), Tile(2,6), Tile(2,7), Tile(2,8), Tile(2,9) ],
        3: [ Tile(3,0), Tile(3,1), Tile(3,2), Tile(3,3), Tile(3,4), Tile(3,5), Tile(3,6), Tile(3,7), Tile(3,8), Tile(3,9) ],
        4: [ Tile(4,0), Tile(4,1), Tile(4,2), Tile(4,3), Tile(4,4), Tile(4,5), Tile(4,6), Tile(4,7), Tile(4,8), Tile(4,9) ],
        5: [ Tile(5,0), Tile(5,1), Tile(5,2), Tile(5,3), Tile(5,4), Tile(5,5), Tile(5,6), Tile(5,7), Tile(5,8), Tile(5,9) ],
        6: [ Tile(6,0), Tile(6,1), Tile(6,2), Tile(6,3), Tile(6,4), Tile(6,5), Tile(6,6), Tile(6,7), Tile(6,8), Tile(6,9) ],
        7: [ Tile(7,0), Tile(7,1), Tile(7,2), Tile(7,3), Tile(7,4), Tile(7,5), Tile(7,6), Tile(7,7), Tile(7,8), Tile(7,9) ],
        8: [ Tile(8,0), Tile(8,1), Tile(8,2), Tile(8,3), Tile(8,4), Tile(8,5), Tile(8,6), Tile(8,7), Tile(8,8), Tile(8,9) ],
        9: [ Tile(9,0), Tile(9,1), Tile(9,2), Tile(9,3), Tile(9,4), Tile(9,5), Tile(9,6), Tile(9,7), Tile(9,8), Tile(9,9) ],
    }

    for i in range(rows):
        for j in range(cols):
            assert created_board.board[i][j].status_code == expected_board[i][j].status_code

    assert created_board.board[0][0].x == 0
    assert created_board.board[0][0].y == 0

    assert created_board.board[4][7].x == 4
    assert created_board.board[4][7].y == 7

def test_check_input():
    test_board = Board()

    user_input = "A1     34"
    assert test_board.check_input(user_input) == (False, ())

    user_input = "A7 S"
    valid, locations = test_board.check_input(user_input)
    assert valid == True
    assert locations[0] == 0
    assert locations[1] == 7
    assert locations[2] == 'S'

def test_check_overlap():
    test_board = Board()
    test_input = "A1 S"
    valid, position = test_board.check_input(test_input)
    valid, locations = test_board.check_overlap(position)
    test_board.place_ship(locations)

    test_input = "A2 E"
    valid, position = test_board.check_input(test_input)
    valid, locations = test_board.check_overlap(position)

    assert valid == True

    test_board.place_ship(locations)
    test_input = "A3 S"
    valid, position = test_board.check_input(test_input)
    valid, locations = test_board.check_overlap(position)

    assert valid == False


def test_place_ship():
    test_board = Board()
    test_input = "A1 S"
    valid, position = test_board.check_input(test_input)
    valid, locations = test_board.check_overlap(position)
    test_board.place_ship(locations)

    assert test_board.board[0][0].status_code == '~'
    assert test_board.board[0][1].status_code == 1
    assert test_board.board[1][1].status_code == 1
    assert test_board.board[2][1].status_code == 1
    assert test_board.board[3][1].status_code == '~'

def test_computer_random_input():
    ROW_IDENTS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
    COL_IDENTS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    VALID_DIRECTIONS = ['N', 'E', 'W', 'S']

    test_board = Board()
    test_ship = test_board.generate_random_input()

    assert test_ship[0] in ROW_IDENTS
    assert test_ship[1] in COL_IDENTS
    assert test_ship[2] in VALID_DIRECTIONS

def test_validate_shot():
    test_board = Board()
    test_shot = 'A 0'
    valid, coordinate = test_board.validate_shots(test_shot)
    assert valid == True

def test_place_shot():
    test_board = Board()
    test_shot = 'A 0'
    valid, test_coordinate = test_board.validate_shots(test_shot)
    assert test_board.place_shot(test_coordinate) == False
    assert test_board.board[0][0].status_code == '*'

def test_computer_random_shot():
    test_board = Board()
    test_ship = test_board.generate_random_shot()

    assert test_ship[0] in range(0,10)
    assert test_ship[1] in range(0,10)

def test_validate_computer_shots():
    test_board = Board()

    assert test_board.validate_computer_shots(0,0)

def test_check_win():
    test_board = Board()

    assert test_board.check_win()

    test_input = "A1 S"
    valid, position = test_board.check_input(test_input)
    valid, locations = test_board.check_overlap(position)
    test_board.place_ship(locations)
    
    assert test_board.check_win() == False