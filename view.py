def start_message():
    print('Welcome to Battleship\n')

def ship_placement(ship_length):
    print('Please enter the coordinates for where to place your ship of length: {}. Ex.( A1 N )'.format(ship_length))

def ship_placement_successful():
    print('The ship was successfully added to the board.')

def ship_placement_invalid():
    print('Your input was either in the incorrect format or the ship would\'ve gone off the board.')

def ship_placement_overlap():
    print('The location you gave overlapped with another ship.')

def fire_shots():
	print('Please enter the coordinates for where to fire your shot. Ex.( A 0 ), or \'X\' for a bonus shot')

def invalid_shot():
    print('You have entered an invalid coordinate location to shoot or you do not have any bonus shots.')

def hit_ship(coordinate):
	print('You have hit a ship at coordinate {}\n'.format(coordinate))

def hit_missed(coordinate):
	print('You have missed your shot at coordinate {}\n'.format(coordinate))

def hit_and_sunk_ship(coordinate):
    print('You\'ve hit a ship at coordinate {} and sunk the ship\n'.format(coordinate))

def start_game():
    print('BEGIN THE GAME!\n')

def print_winner(name):
    print('The {} won!'.format(name))

def print_score(name, score):
    print('The {}\'s cumulative score is {} points.'.format(name, score))

def play_again():
    print('\nWould you like to play again? (y=yes, n=no)')

def invalid_input_on_play_again():
    print('Please enter either \'y\' or \'n\'.')

def bonus_shot_prompt(bonus_shots):
    print('How many bonus shots do you want to use? Available: {}'.format(bonus_shots))