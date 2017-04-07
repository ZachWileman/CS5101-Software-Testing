from tile import Tile
from board import Board

def test_create_board():
    rows = 10
    cols = 20

    created_board = Board()
    expected_board = [[Tile() for i in range(cols)] for j in range(rows)]

    for i in range(rows):
        for j in range(cols):
            assert created_board.board[i][j].status_code == expected_board[i][j].status_code
