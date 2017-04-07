from tile import Tile

global COL_IDENTS
global ROW_IDENTS
global VALID_DIRECTIONS
COL_IDENTS = [' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
ROW_IDENTS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
VALID_DIRECTIONS = ['N', 'E', 'W', 'S']

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

    def check_input(self, ship_placement):
        # TODO: Need to also make sure that ships don't overlap

        global COL_IDENTS
        global ROW_IDENTS

        ship_placement = "".join(ship_placement.split())

        if len(ship_placement) != 3:
            return False
        if ship_placement[0] not in COL_IDENTS:
            return False
        if ship_placement[1] not in ROW_IDENTS:
            return False
        if ship_placement[2] not in VALID_DIRECTIONS:
            return False

        ship_start_horizontal = ord(ship_placement[0]) - 65 # A B C . . .
        ship_start_vertical = int(ship_placement[1]) # 0 1 2 . . .
        ship_end_vertical = None
        ship_end_horizontal = None
        direction = ship_placement[2]

        if direction == 'N':
            ship_end_vertical = ship_start_vertical - 2
            if ship_end_vertical < 0:
                return False

        if direction == 'S':
            ship_end_vertical = ship_start_vertical + 2
            if ship_end_vertical > self.rows-1:
                return False

        if direction == 'W':
            ship_end_horizontal = ship_start_horizontal - 2
            if ship_end_horizontal < 0:
                return False

        if direction == 'E':
            ship_end_horizontal = ship_start_horizontal + 2
            if ship_end_horizontal > self.cols-1:
                return False

        return True
