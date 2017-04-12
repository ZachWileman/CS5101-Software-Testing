class Tile():

    def __init__(self, x, y):
        ''' STATUS CODES

        -2 = SUNK
        -1 = MISS

         ~ = INITIAL (water)
         1 = SHIP

         2 = HIT
         3 = SHIP_LENGTH
        '''

        self.status_code = '~'
        self.x = x
        self.y = y
