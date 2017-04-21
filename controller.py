from random import random
from board import Board
from tile import Tile
import view as View

if __name__ == '__main__':
    num_starting_ships = 3
    valid_inputs = 0
    keep_playing = True

    while keep_playing:
        View.start_message()
        user_board = Board()
        computer_board = Board()

        user_board.print_board('User')

        # User places ships onto their board
        while valid_inputs != num_starting_ships:
            View.ship_placement()
            ship = input('')
            valid, position = user_board.check_ship_placement_input(ship)
            if valid:
                valid, locations = user_board.check_overlap(position)
                if valid:
                    user_board.place_ship(locations)
                    View.ship_placement_successful()
                    user_board.print_board('User')
                    valid_inputs += 1
                else:
                    View.ship_placement_overlap()
            else:
                View.ship_placement_invalid()

        valid_inputs = 0

        # Load up computer's board with initial ships
        while valid_inputs != num_starting_ships:
            ship = computer_board.generate_random_input(True)
            valid, position = computer_board.check_ship_placement_input(ship)
            if valid:
                valid, locations = computer_board.check_overlap(position)
                if valid:
                    computer_board.place_ship(locations)
                    valid_inputs += 1

        valid_inputs = 0 # Set to zero in case their is another game played
        View.start_game()

        # Loops until a winner is found
        while True:

            valid = False
            user_coordinate = None
            comp_coordinate = None
            user_coordinate_converted = None
            comp_coordinate_converted = None

            # Print out the user's shot board and ship board
            # Along with the computer's board for demonstration purposes
            computer_board.print_shot_board()
            user_board.print_board('User')
            computer_board.print_board('Computer')

            # Loops until the user enters a valid shot
            while True:
                View.fire_shots()
                user_shot = input('')
                valid, user_coordinate = computer_board.check_shot_input(user_shot)
                if valid:
                    user_coordinate_converted = computer_board.convert_input(user_coordinate)
                    if computer_board.validate_shot(*user_coordinate_converted):
                        break
                    else:
                        View.invalid_shot()
                else:
                    View.invalid_shot()

            # Update computer board with user's shot
            if computer_board.place_shot(user_coordinate_converted):

                # Check if a ship was sunk with the hit
                if computer_board.update_ships():
                    View.hit_and_sunk_ship(user_coordinate)
                else:
                    View.hit_ship(user_coordinate)

                # Checks for winner
                if computer_board.check_win():
                    View.print_winner('user')
                    break

            # Otherwise, prints shot missed
            else:
                View.hit_missed(user_coordinate)

            # Computer's turn to shoot
            while True:
                comp_coordinate = user_board.generate_random_input(False)
                comp_coordinate = user_board.convert_input(comp_coordinate)
                if user_board.validate_shot(*comp_coordinate):
                    user_board.place_shot(comp_coordinate)
                    break

            # Updates user's board with computers shots
            user_board.place_shot(comp_coordinate)
            user_board.update_ships()

            # Check for win condition
            if user_board.check_win():
                View.print_winner('computer')
                break

        # Asks user if they would like to play again & validates input
        while True:
            View.play_again()
            keep_playing_choice = input('')

            if keep_playing_choice == 'y' or keep_playing_choice == 'n':
                break

            View.invalid_input_on_play_again()

        if keep_playing_choice == 'n':
            keep_playing = False
