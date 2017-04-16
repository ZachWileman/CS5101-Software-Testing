from random import random
from board import Board
from tile import Tile
import view as View

if __name__ == '__main__':
    num_starting_ships = 3 
    num_inputs = 0
    View.start_message()

    user_board = Board()
    computer_board = Board()

    """
    user_board.print_board()
    #user input ships
    while num_inputs != num_starting_ships:
        View.ship_placement()
        ship = input('')
        valid, position = user_board.check_input(ship)
        if valid:
            valid, locations = user_board.check_overlap(position)
            if valid:
                user_board.place_ship(locations)
                View.ship_placement_successful()
                user_board.print_board()
                num_inputs += 1
            else:
                View.ship_placement_overlap()
        else:
            View.ship_placement_invalid()
    """
    #computer input ships
    while num_inputs != num_starting_ships:
        ship = computer_board.generate_random_input()
        valid, position = computer_board.check_input(ship)
        if valid:
            valid, locations = computer_board.check_overlap(position)
            if valid:
                computer_board.place_ship(locations)
                num_inputs += 1

    omputer_board.print_board()