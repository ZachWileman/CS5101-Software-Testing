class Tile():

    def __init__(self):
        ''' STATUS CODES

        -2 = SUNK
        -1 = MISS
         0 = INITIAL
         1 = HIT
         3 = SHIP_LENGTH
        '''

        self.status_code = '~'
