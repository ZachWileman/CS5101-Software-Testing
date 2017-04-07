from tile import Tile

class Board():

    def __init__(self):
        self.board = []
        self.rows = 10
        self.cols = 20

        # Board Size = 10x20
        self.board = [[Tile() for i in range(self.cols)] for j in range(self.rows)]

    def print_board(self):
        for i in range(self.rows):
            for j in range(self.cols):
                print('{} '.format(self.board[i][j].status_code), end='')

            print('')
