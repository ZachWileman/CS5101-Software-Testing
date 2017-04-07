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
        if board.check_input(ship):
            print('Valid input')
        else:
            print('Invalid input')
