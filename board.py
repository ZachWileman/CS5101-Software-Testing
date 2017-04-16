from tile import Tile
import random

global COL_IDENTS
global ROW_IDENTS
global VALID_DIRECTIONS
ROW_IDENTS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
COL_IDENTS = [' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
VALID_DIRECTIONS = ['N', 'E', 'W', 'S']

class Board():

    def __init__(self):
        self.board = {}
        self.rows = 10
        self.cols = 10
        self.ships = {}

        for i in range(self.rows):
            self.board[i] = []
            for j in range(self.cols):
                self.board[i].append(Tile(i,j))

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

    def print_shot_board(self):
        global COL_IDENTS
        global ROW_IDENTS

        for i in range(len(COL_IDENTS)):
            print('{} '.format(COL_IDENTS[i]), end='')
        print('')

        for i in range(self.rows):
            print('{} '.format(ROW_IDENTS[i]), end='')

            for j in range(self.cols):
                if self.board[i][j].status_code == 1:
                    print('~ ', end='')
                else:
                    print('{} '.format(self.board[i][j].status_code), end='')

            print('')

    def check_input(self, ship_placement):
        global COL_IDENTS
        global ROW_IDENTS

        # Strips the user's input of all spaces
        ship_placement = "".join(ship_placement.split())

        # Validates the user input a valid number of characters and that the characters were
        # valid eligible characters
        if len(ship_placement) != 3:
            return (False, ())
        if ship_placement[0] not in ROW_IDENTS:
            return (False, ())
        if ship_placement[1] not in COL_IDENTS:
            return (False, ())
        if ship_placement[2] not in VALID_DIRECTIONS:
            return (False, ())

        # Grabs the individual pieces of data from the stripped user input
        ship_start_row = ord(ship_placement[0]) - 65 # A B C . . .
        ship_start_col = int(ship_placement[1]) # 0 1 2 . . .
        direction = ship_placement[2]

        # Checks if the users input would end up making the ship go off the board
        if direction == 'N':
            if (ship_start_row - 2) < 0:
                return (False, ())

        elif direction == 'S':
            if (ship_start_row + 2) >= self.rows:
                return (False, ())

        elif direction == 'W':
            if (ship_start_col - 2) < 0:
                return (False, ())

        elif direction == 'E':
            if (ship_start_col + 2) >= self.cols:
                return (False, ())

        return (True, (ship_start_row, ship_start_col, direction))

    def check_overlap(self, position):
        # Grab initial placement of ship with direction
        x = position[0]
        y = position[1]
        direction = position[2]

        # Add initial tile locations
        locations = []

        # Grab all locations that will be set to a ship
        if direction == 'N':
            for i in range(3):
                locations.append(self.board[x-i][y])

        elif direction == 'E':
            for i in range(3):
                locations.append(self.board[x][y+i])

        elif direction == 'S':
            for i in range(3):
                locations.append(self.board[x+i][y])

        elif direction == 'W':
            for i in range(3):
                locations.append(self.board[x][y-i])

        # Check if ships overlap
        for tiles in self.ships.values():
            for tile in tiles:
                if tile in locations:
                    # Invalid
                    return (False, None)

        # Valid
        return (True, locations)

    def place_ship(self, locations):
        # Add ship to self.ships
        self.ships[len(self.ships)] = locations

        # Sets tile locations to have a "status_code" of 1; meaning they're a ship
        for tile in locations:
            self.board[tile.x][tile.y].status_code = 1

    def generate_random_input(self):
        computer_input = ""
        
        #gets random row input
        num_random = random.randint(0,9)
        row_random = ROW_IDENTS[num_random]
        computer_input += row_random

        #gets random col input
        num_random = random.randint(1,10)
        col_random = COL_IDENTS[num_random]
        computer_input += col_random

        #gets random direction input
        num_random = random.randint(0,3)
        dir_random = VALID_DIRECTIONS[num_random]
        computer_input += dir_random

        return computer_input

    def validate_shots(self, coordinate_shot):

        # Strips the user's input of all spaces
        coordinate_shot = "".join(coordinate_shot.split())

        # Validates the user input a valid number of characters and that the characters were
        # valid eligible characters
        if len(coordinate_shot) != 2:
            return (False, ())
        if coordinate_shot[0] not in ROW_IDENTS:
            return (False, ())
        if coordinate_shot[1] not in COL_IDENTS:
            return (False, ())

        # Grabs the individual pieces of data from the stripped user input
        ship_start_row = ord(coordinate_shot[0]) - 65 # A B C . . .
        ship_start_col = int(coordinate_shot[1]) # 0 1 2 . . .

        tile_shot = self.board[ship_start_row][ship_start_col]
        if tile_shot.status_code == 'X' or tile_shot.status_code == '*':
            return (False, ())
        else:
            return (True, (ship_start_row, ship_start_col))

    def place_shot(self, coordinate_shot):
        board_tile = self.board[coordinate_shot[0]][coordinate_shot[1]]
        
        if board_tile.status_code == 1:
            board_tile.status_code = 'X'
            return True
        elif board_tile.status_code == '~':
            board_tile.status_code = '*'
            return False
        
        return False

    def generate_random_shot(self):
        computer_input = ""
        
        #gets random row input
        num_random = random.randint(0,9)
        row_random = ROW_IDENTS[num_random]
        computer_input += row_random

        #gets random col input
        num_random = random.randint(1,10)
        col_random = COL_IDENTS[num_random]
        computer_input += col_random

        return computer_input