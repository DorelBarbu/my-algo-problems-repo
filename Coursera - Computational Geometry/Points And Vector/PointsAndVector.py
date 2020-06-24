ON_SEGMENT = "ON_SEGMENT"
ON_LINE = "ON_LINE"
LEFT = "LEFT"
RIGHT = "RIGHT"

class Point2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

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

#Test case 1:
v = Vector2D(Point2D(-4, 4), Point2D(2, -2))
N = 4
points = [Point2D(0, 0), Point2D(5, -5), Point2D(1, 1), Point2D(-1, -1)]
for p in points:
    print(v.determineRelativePosition(p))
print("#########")

#Test case 2:
v = Vector2D(Point2D(-4, 0), Point2D(2, -10))
N = 8
points = [Point2D(-8, 4), Point2D(2, -7), Point2D(9, 3), Point2D(-4, 6), Point2D(-8, -5), Point2D(7, 1), Point2D(2, 4), Point2D(-3, -9)]
for p in points:
    print(v.determineRelativePosition(p))