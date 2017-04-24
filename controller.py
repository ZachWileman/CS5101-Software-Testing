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
    count = 0

    while keep_playing:
        View.start_message()
        user_board = Board()
        computer_board = Board()
        user_board.generate_computers_random_shots()

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
                    if user_shot == 'X' and computer_board.bonus_shot > 0: # BONUS SHOT
                        while True:
                            View.bonus_shot_prompt(computer_board.bonus_shot)
                            bonus_shot_count = input('')
                            bonus_shot_count = int(bonus_shot_count)
                            if bonus_shot_count > 0 and bonus_shot_count <= computer_board.bonus_shot:
                                break

                        for i in range(bonus_shot_count):
                            View.fire_shots()
                            user_shot = input('')
                            valid, user_coordinate = computer_board.check_shot_input(user_shot)
                            if valid:
                                user_coordinate_converted = computer_board.convert_input(user_coordinate)
                                if computer_board.validate_shot(*user_coordinate_converted):
                                    do_nothing = 0
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
                            
                            computer_board.print_shot_board()
                            user_board.print_board('User')
                            computer_board.print_board('Computer')
                        
                        computer_board.bonus_shot -= bonus_shot_count # reduces bonus_shot_count for user depending on how many he/she uses
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
                smart_shot_found, comp_coordinate = user_board.generate_smart_shot()

                # If no smart shot found, genereate a random shot
                if not smart_shot_found:
                    comp_coordinate = user_board.select_random_shot()

                user_board.place_shot(comp_coordinate)
                break
                
            # Computer checks if it has a bonus shot, it runs if it has a bonus shot
            if user_board.bonus_shot > 0:
                while True:
                    smart_shot_found, comp_coordinate = user_board.generate_smart_shot()

                    # If no smart shot found, genereate a random shot
                    if not smart_shot_found:
                        comp_coordinate = user_board.select_random_shot()

                    user_board.place_shot(comp_coordinate)
                    break

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

        # Resets bonus shots
        computer_board.bonus_shot = 0
        user_board.bonus_shot = 0

        # Asks user if they would like to play again & validates input
        while True:
            View.play_again()
            keep_playing_choice = input('')

            if keep_playing_choice == 'y' or keep_playing_choice == 'n':
                break

            View.invalid_input_on_play_again()

        if keep_playing_choice == 'n':
            keep_playing = False
