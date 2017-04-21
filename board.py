from tile import Tile
from random import randint

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
        self.num_ship_hits = 0 # The amount of times a shot hit a shit
        self.num_ships_sunk = 0
        self.ships = {}

        for i in range(self.rows):
            self.board[i] = []
            for j in range(self.cols):
                self.board[i].append(Tile(i,j))

    def print_board(self, name):
        print('--- {}\'s ship board ---'.format(name))

        for i in range(len(COL_IDENTS)):
            print('{} '.format(COL_IDENTS[i]), end='')
        print('')

        for i in range(self.rows):
            print('{} '.format(ROW_IDENTS[i]), end='')

            for j in range(self.cols):
                print('{} '.format(self.board[i][j].status_code), end='')

            print('')
        print('')

    def print_shot_board(self):
        print('--- User\'s shot board ---')

        for i in range(len(COL_IDENTS)):
            print('{} '.format(COL_IDENTS[i]), end='')
        print('')

        for i in range(self.rows):
            print('{} '.format(ROW_IDENTS[i]), end='')

            for j in range(self.cols):
                if self.board[i][j].status_code == '!':
                    print('~ ', end='')
                else:
                    print('{} '.format(self.board[i][j].status_code), end='')

            print('')
        print('')

    def check_ship_placement_input(self, ship_placement):
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

        # Sets tile locations to have a "status_code" of !; meaning they're a ship
        for tile in locations:
            self.board[tile.x][tile.y].status_code = '!'

    # Used for generating random input for placing ships & firing shots
    def generate_random_input(self, placing_a_ship):
        computer_input = ""

        #gets random row input
        num_random = randint(0,(len(ROW_IDENTS)-1))
        row_random = ROW_IDENTS[num_random]
        computer_input += row_random

        #gets random col input
        num_random = randint(1,(len(COL_IDENTS)-1))
        col_random = COL_IDENTS[num_random]
        computer_input += col_random

        if placing_a_ship:
            #gets random direction input
            num_random = randint(0,(len(VALID_DIRECTIONS)-1))
            dir_random = VALID_DIRECTIONS[num_random]
            computer_input += dir_random

        return computer_input

    def check_shot_input(self, coordinate_shot):

        # Strips the user's input of all spaces
        coordinate_shot = "".join(coordinate_shot.split())

        # Validates the user input a valid number of characters and that the characters were
        # valid eligible characters
        if len(coordinate_shot) != 2:
            return (False, None)
        if coordinate_shot[0] not in ROW_IDENTS:
            return (False, None)
        if coordinate_shot[1] not in COL_IDENTS:
            return (False, None)

        return (True, coordinate_shot)

    def convert_input(self, coordinate_shot):
        # Grabs the individual pieces of data from the stripped user input
        row = ord(coordinate_shot[0]) - 65 # A B C . . .
        col = int(coordinate_shot[1]) # 0 1 2 . . .

        return (row,col)

    def validate_shot(self, row, col):
        # Gets the status code of the tile being shot at
        tile_status = self.board[row][col].status_code
        valid_locations = ['!', '~']

        # Makes sure the user is shooting a place they've already tried
        if tile_status in valid_locations:
            return True
        else:
            return False

    def place_shot(self, coordinate):
        tile_status = self.board[coordinate[0]][coordinate[1]].status_code

        # Hit a ship
        if tile_status == '!':
            self.board[coordinate[0]][coordinate[1]].status_code = 'X'
            self.num_ship_hits += 1
            return True
        # Hit the water
        elif tile_status == '~':
            self.board[coordinate[0]][coordinate[1]].status_code = '*'
            return False

        return False

    def update_ships(self):
        ships_to_be_removed = {}

        # Checks if any of the ships are completely sunk
        for ship_id, ship_tiles in self.ships.items():
            ship_sunk = True

            for tile in ship_tiles:
                if tile.status_code != 'X':
                    ship_sunk = False
                    break

            # If a ship got completely hit, queue it up to be sunk
            if ship_sunk:
                ships_to_be_removed[ship_id] = ship_tiles

        # Removes any sunk ships from the self.ships variable and also updates the board
        # about the sunk ship.
        for ship_id, ship_tiles in ships_to_be_removed.items():
            for tile in ship_tiles:
                self.board[tile.x][tile.y].status_code = 'S'
            self.ships.pop(ship_id)

        # Returns true if a ship sunk
        if ships_to_be_removed:
            self.num_ships_sunk += 1
            return True

        return False

    def compute_game_score(self):
        return self.num_ship_hits + (5 * self.num_ships_sunk)

    def check_win(self):
        if self.ships:
            return False

        return True
