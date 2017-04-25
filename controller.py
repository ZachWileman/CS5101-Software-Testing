from random import random
from board import Board
from tile import Tile
import view as View

if __name__ == '__main__':
    num_starting_ships = 4
    valid_inputs = 0
    keep_playing = True
    user_score = 0
    computer_score = 0

    while keep_playing:
        View.start_message()
        user_board = Board()
        computer_board = Board()
        user_board.generate_computers_random_shots()
        winner_found = False

        user_board.print_board('User')

        # User places ships onto their board
        while valid_inputs != num_starting_ships:
            View.ship_placement((5 - valid_inputs))
            ship = input('')

            # Users insert different sized ships starting with length 5 and going to length 2
            valid, position = user_board.check_ship_placement_input(ship, (5 - valid_inputs))
            if valid:
                valid, locations = user_board.check_overlap(position, (5 - valid_inputs))
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
            ship = computer_board.generate_random_ship_placement()
            valid, position = computer_board.check_ship_placement_input(ship, (5 - valid_inputs))
            if valid:
                valid, locations = computer_board.check_overlap(position, (5 - valid_inputs))
                if valid:
                    computer_board.place_ship(locations)
                    valid_inputs += 1

        valid_inputs = 0 # Set to zero in case their is another game played
        View.start_game()

        # Loops until a winner is found
        while not winner_found:

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

            # Default values set for when getting user input on shot locations
            num_shots_left = 1

            # Loops until the user uses all of the current shots
            while num_shots_left:

                # Loops until the user enters a valid shot
                while True:
                    # Default values set for when getting user input on shot locations
                    user_shot = 'X'

                    # Loops until the user doesn't try to input extra shots
                    while user_shot == 'X':
                        View.fire_shots()
                        user_shot = input('')

                        # If the user wants to use their extra shots
                        if user_shot == 'X':
                            View.num_bonus_shots(computer_board.bonus_shots)
                            num_bonus_shots = input('')

                            # If the user entered a valid number
                            if computer_board.validate_bonus_shots(num_bonus_shots):
                                View.add_bonus_shots(num_bonus_shots)
                                num_shots_left += int(num_bonus_shots)
                            else:
                                View.invalid_bonus_shot_input()

                    # Validates user's input and prints messages accordingly
                    valid, user_coordinate = computer_board.check_shot_input(user_shot)
                    if valid:
                        user_coordinate_converted = computer_board.convert_input(user_coordinate)
                        if computer_board.validate_shot(*user_coordinate_converted):
                            num_shots_left -= 1
                            break
                        else:
                            View.invalid_shot()
                    else:
                        View.invalid_shot()

                # Checks for aoe shot
                if computer_board.aoe_shot:
                    computer_board.place_aoe_shot(user_coordinate_converted)
                else:
                    # Update computer board with user's shot
                    if computer_board.place_shot(user_coordinate_converted):

                        # Check if a ship was sunk with the hit
                        if computer_board.update_ships():
                            View.hit_and_sunk_ship(user_coordinate)
                        else:
                            View.hit_ship(user_coordinate)

                    # Otherwise, prints shot missed
                    else:
                        View.hit_missed(user_coordinate)

                # Checks for winner
                if computer_board.check_win():
                    winner_found = True
                    break

            if winner_found:
                View.print_winner('user')
                break

            # Adds 1 for each of the computers turn; being used for two purposes rather
            # than creating a new counter variable in the controller
            user_board.bonus_shots += 1

            # Computer's turn to shoot; loops until its used all of its availble shots
            while user_board.bonus_shots:
                smart_shot_found, comp_coordinate = user_board.generate_smart_shot()

                # If no smart shot found, generate a random shot
                if not smart_shot_found:
                    comp_coordinate = user_board.select_random_shot()

                if user_board.aoe_shot:
                    user_board.place_aoe_shot(comp_coordinate)
                else:
                    user_board.place_shot(comp_coordinate)

                user_board.bonus_shots -= 1

            # Updates user's board with computers shots
            user_board.place_shot(comp_coordinate)
            user_board.update_ships()

            # Check for win condition
            if user_board.check_win():
                View.print_winner('computer')
                break

        # Compute the user and computers score
        user_score += computer_board.compute_game_score()
        computer_score += user_board.compute_game_score()

        # Print the scores
        View.print_score('user', user_score)
        View.print_score('computer', computer_score)

        # Asks user if they would like to play again & validates input
        while True:
            View.play_again()
            keep_playing_choice = input('')

            if keep_playing_choice == 'y' or keep_playing_choice == 'n':
                break

            View.invalid_input_on_play_again()

        if keep_playing_choice == 'n':
            keep_playing = False
