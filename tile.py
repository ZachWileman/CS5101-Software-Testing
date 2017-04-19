class Tile():

    def __init__(self, x, y):
        ''' STATUS CODES

        ~ = INITIAL (water)
        ! = SHIP
        * = MISS
        X = HIT
        S = SUNK

        '''

        self.status_code = '~'
        self.x = x
        self.y = y
