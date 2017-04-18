def start_message():
    print('Welcome to Battleship')

def ship_placement():
    print('Please enter the coordinates for where to place your 3 ships. Ex.( A1 N )')

def ship_placement_successful():
    print('The ship was successfully added to the board.')

def ship_placement_invalid():
    print('Your input was either in the incorrect format or the ship would\'ve gone off the board.')

def ship_placement_overlap():
    print('The location you gave overlapped with another ship.')

def fire_shots():
	print('Please enter the coordinates for where to fire your shot. Ex.( A 0 )')

def shot_response_true(coordinate):
	print('You have hit a ship at coordinate {}'.format(coordinate))

def shot_response_false(coordinate):
	print('You have missed your shot at coordinate {}'.format(coordinate))	

def board_name(name):
	print('{}\'s board'.format(name))