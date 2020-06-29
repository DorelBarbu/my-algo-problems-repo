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
        
        if position1 == LEFT and position2 == LEFT and position3 == LEFT:
            return INSIDE
        
        if position1 == RIGHT and position2 == RIGHT and position3 == RIGHT:
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
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
    def determineRelativePosition(self, p):
        det = GeometryUtils.calculateDeterminant(self.start, self.end, p)
        if det < 0:
            return RIGHT
        if det > 0:
            return LEFT

        minX = min(self.start.x, self.end.x)
        maxX = max(self.start.x, self.end.x)

        if minX <= p.x and p.x <= maxX:
            return ON_SEGMENT
        else:
            return ON_LINE

#Test 1
t = Triangle(Point2D(0, 0), Point2D(5, 5), Point2D(0, 6))
points = [Point2D(3, 3), Point2D(6, 6), Point2D(2, 3)]
for p in points:
    print(t.determineRelativePosition(p))


#Test 2
t = Triangle(Point2D(1, 0), Point2D(0, 3), Point2D(3, 3))
points = [
    Point2D(0, 0), Point2D(0, 1), Point2D(0, 2), Point2D(0, 3), Point2D(1, 0), Point2D(1, 1), Point2D(1, 2),
    Point2D(1, 3), Point2D(2, 0), Point2D(2, 1), Point2D(2, 2), Point2D(2, 3)
]
for p in points:
    print(t.determineRelativePosition(p))