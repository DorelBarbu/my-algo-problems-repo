OUTSIDE = 'OUTSIDE'
INSIDE = 'INSIDE'
BORDER = 'BORDER'
ON_SEGMENT = "ON_SEGMENT"
ON_LINE = "ON_LINE"
LEFT = "LEFT"
RIGHT = "RIGHT"


class Point2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Triangle:
    def __init__(self, a: Point2D, b: Point2D, c: Point2D):
        self.ab = Vector2D(a, b)
        self.bc = Vector2D(b, c)
        self.ca = Vector2D(c, a)
    
    def determineRelativePosition(self, p: Point2D):
        position1 = self.ab.determineRelativePosition(p)
        position2 = self.bc.determineRelativePosition(p)
        position3 = self.ca.determineRelativePosition(p)
        
        if position1 == ON_SEGMENT or position2 == ON_SEGMENT or position3 == ON_SEGMENT:
            return BORDER
        
        if position1 == LEFT and position2 == LEFT or position3 == LEFT:
            return INSIDE
        
        if position1 == RIGHT and position2 == RIGHT or position3 == RIGHT:
            return INSIDE
        
        return OUTSIDE
        

class GeometryUtils:
    @staticmethod
    def calculateDeterminant(a, b, p):
        return (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y)
    
    @staticmethod
    def calculateSquareDistance(a, b):
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)

class Vector2D:
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail
    
    def determineRelativePosition(self, p):
        det = GeometryUtils.calculateDeterminant(self.head, self.tail, p)
        if det < 0:
            return RIGHT
        if det > 0:
            return LEFT

        if GeometryUtils.calculateSquareDistance(self.head, self.tail) <= GeometryUtils.calculateSquareDistance(self.head, p):
            return ON_SEGMENT
        else:
            return ON_LINE

#Test 1
t = Triangle(Point2D(0, 0), Point2D(5, 5), Point2D(0, 6))