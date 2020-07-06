OUTSIDE = 'OUTSIDE'
INSIDE = 'INSIDE'
BORDER = 'BORDER'
ON_SEGMENT = "ON_SEGMENT"
ON_LINE = "ON_LINE"
LEFT = "LEFT"
RIGHT = "RIGHT"
LOWER = "LOWER"
UPPER = "UPPER"
MIDDLE = "MIDDLE"


class Point2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return "{" + str(self.x) + ", " + str(self.y) + "}"

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


class GeometryUtils:
    @staticmethod
    def calculateDeterminant(a, b, p):
        return (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y)
    
    @staticmethod
    def calculateSquareDistance(a, b):
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)
    
    #q is the right point of the, which stars at -infinity, and w is a segment arbitrarily oriented
    @staticmethod
    def determineVectorIntersectionWithHorizontalLine(q: Point2D, w: Vector2D):
        lowerSegmentPoint = w.start if w.start.y < w.end.y else w.end
        upperSegmentPoint = w.start if w.start.y > w.end.y else w.end

        wOriented = Vector2D(lowerSegmentPoint, upperSegmentPoint)
        
        return lowerSegmentPoint.y <= q.y and q.y <= upperSegmentPoint.y and wOriented.determineRelativePosition(q) == RIGHT
    
    @staticmethod
    def isHorizontalLineCrossingSegmentExtremity(q: Point2D, w:Vector2D):
        lowerSegmentPoint = w.start if w.start.y < w.end.y else w.end
        upperSegmentPoint = w.start if w.start.y > w.end.y else w.end

        if lowerSegmentPoint.y == q.y:
            return LOWER
        if upperSegmentPoint.y == q.y:
            return UPPER

        return MIDDLE


class Polygon:
    def __init__(self, points):
        self.points = points
        self.numberOfPoints = len(points)
    
    def determineRelativePosition(self, targetPoint):
        numberOfIntersections = 0
        for i in range(self.numberOfPoints):
            currentEdge = Vector2D(self.points[i], self.points[(i + 1) % self.numberOfPoints])
            if currentEdge.determineRelativePosition(targetPoint) == ON_SEGMENT:
                return BORDER
            if GeometryUtils.determineVectorIntersectionWithHorizontalLine(targetPoint, currentEdge):
                crossingType = GeometryUtils.isHorizontalLineCrossingSegmentExtremity(targetPoint, currentEdge)
                if crossingType == LOWER or crossingType == MIDDLE:
                    numberOfIntersections += 1

        return INSIDE if numberOfIntersections % 2 == 1 else OUTSIDE




#Test 1
polygonPoints = [
    Point2D(-3, -1),
    Point2D(3, -1),
    Point2D(3, 5),
    Point2D(0, 2),
    Point2D(-3, 4)
]

points = [
    Point2D(1, 3),
    Point2D(-1, 3),
    Point2D(0, 0),
    Point2D(-2, 3),
    Point2D(0, 6),
    Point2D(-1, 0),
    Point2D(-4, 2),
    Point2D(-4, -1),
    Point2D(-2, 2)
]

polygon = Polygon(polygonPoints)
for p in points:
    print(p, polygon.determineRelativePosition(p))
# print(polygon.determineRelativePosition(points[3]))