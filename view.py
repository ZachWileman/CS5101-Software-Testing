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
	print('Please enter the coordinates for where to fire your shot. '+
          'Ex.( A 0 ) Or enter X to add bonus shots to your current number of shots available.')

def num_bonus_shots(num_shots_available):
    print('Please enter the number of bonus shots you\'d like to use. Available bonus shots: {}'.format(num_shots_available))

def add_bonus_shots(num_shots):
    print('Added {} shot(s) to your currently available shots.'.format(num_shots))

def invalid_bonus_shot_input():
    print('You\'ve entered an invalid number of bonus shots.')

def invalid_shot():
    print('You have entered an invalid coordinate location to shot.')

def hit_ship(coordinate):
	return 'You have hit a ship at coordinate {}\n'.format(coordinate)

def hit_missed(coordinate):
	return 'You have missed your shot at coordinate {}\n'.format(coordinate)

def hit_and_sunk_ship(coordinate):
    return 'You\'ve hit a ship at coordinate {} and sunk the ship\n'.format(coordinate)

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
