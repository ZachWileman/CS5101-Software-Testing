from board import Board
from tile import Tile
import view as View


if __name__ == '__main__':
    View.start_message()

    board = Board()
    board.print_board()

    while True:
        View.ship_placement()
        ship = input('')
        valid, position = board.check_input(ship)
        if valid:
            valid, locations = board.check_overlap(position)
            if valid:
                board.place_ship(locations)
                View.ship_placement_successful()
                board.print_board()
            else:
                View.ship_placement_overlap()
        else:
            View.ship_placement_invalid()
