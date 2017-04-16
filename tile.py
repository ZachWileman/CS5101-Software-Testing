class Tile():

    def __init__(self, x, y):
        ''' STATUS CODES

        -2 = SUNK
         * = MISS

         ~ = INITIAL (water)
         1 = SHIP

         X = HIT
        '''

        self.status_code = '~'
        self.x = x
        self.y = y
