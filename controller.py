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

    View.board_name('User')
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
                View.board_name('User')
                user_board.print_board()
                num_inputs += 1
            else:
                View.ship_placement_overlap()
        else:
            View.ship_placement_invalid()
    
    num_inputs = 0
    #computer input ships
    while num_inputs != num_starting_ships:
        ship = computer_board.generate_random_input()
        valid, position = computer_board.check_input(ship)
        if valid:
            valid, locations = computer_board.check_overlap(position)
            if valid:
                computer_board.place_ship(locations)        
                num_inputs += 1
    # View.board_name('Computer')
    computer_board.print_board()

    #shots are fired
    while True: #while winner is not found
        #user fire shots
        View.fire_shots()
        user_shot = input('')
        valid, user_coordinate = computer_board.validate_shots(user_shot)
        if valid:
            #update computer board
            if computer_board.place_shot(user_coordinate):
                View.shot_response_true(user_coordinate)
                if computer_board.check_win():
                    print('User won!')
                    # View.board_name('Computer')
                    # computer_board.print_board()
                    break

            else:
                View.shot_response_false(user_coordinate)
                # print('---Shot board---')
                # computer_board.print_shot_board()
            print('---Shot board---')
            computer_board.print_shot_board()
            #computer's turn to shoot            
            while True:
                computer_shot = computer_board.generate_random_shot()
                if computer_board.validate_computer_shots(*computer_shot):
                    user_board.place_shot(computer_shot)
                    break
            # check for win condition
            if user_board.check_win():
                print('Computer won!')
                break
            View.board_name('User')
            user_board.print_board()