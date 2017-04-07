from tile import Tile

global COL_IDENTS
global ROW_IDENTS
COL_IDENTS = [' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
ROW_IDENTS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

class Board():

    def __init__(self):
        self.board = []
        self.rows = 10
        self.cols = 10

        # Board Size = 10x20
        self.board = [[Tile() for i in range(self.cols)] for j in range(self.rows)]

    def print_board(self):
        global COL_IDENTS
        global ROW_IDENTS

        for i in range(len(COL_IDENTS)):
            print('{} '.format(COL_IDENTS[i]), end='')
        print('')

        for i in range(self.rows):
            print('{} '.format(ROW_IDENTS[i]), end='')

            for j in range(self.cols):
                print('{} '.format(self.board[i][j].status_code), end='')

            print('')
