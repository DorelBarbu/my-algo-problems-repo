import unittest
from PointInclusionInConvexPolygon import createCmp
from PointInclusionInConvexPolygon import Point
from PointInclusionInConvexPolygon import det
from PointInclusionInConvexPolygon import findWedge
from PointInclusionInConvexPolygon import computeCenterOfMass

class TestWedgeFunction(unittest.TestCase):
    def test_wedge_2(self):
        polygon = [
            Point(-2, -3),
            Point(1, -4),
            Point(3, -2),
            Point(2, 1),
            Point(-2, 1)
        ]
        M = computeCenterOfMass(polygon)
        p = Point(2, -2)
        wedge = findWedge(polygon, M, p)
        # print('Wedge is ', wedge)
        self.assertTrue(wedge == 2, "Wedge should be 2, instead is " + str(wedge))
    
    def test_wedge_1(self):
        polygon = [
            Point(-2, -3),
            Point(1, -4),
            Point(3, -2),
            Point(2, 1),
            Point(-2, 1)
        ]
        M = computeCenterOfMass(polygon)
        p = Point(2, -3)
        wedge = findWedge(polygon, M, p)
        # print('Wedge is ', wedge)
        self.assertTrue(wedge == 1, "Wedge should be 1, instead is " + str(wedge))
    
    def test_wedge_3(self):
        polygon = [
            Point(-2, -3),
            Point(1, -4),
            Point(3, -2),
            Point(2, 1),
            Point(-2, 1)
        ]
        M = computeCenterOfMass(polygon)
        p = Point(0, -2)
        wedge = findWedge(polygon, M, p)
        # print('Wedge is ', wedge)
        self.assertTrue(wedge == 3, "Wedge should be 3, instead is " + str(wedge))
    
    def test_wedge_0(self):
        polygon = [
            Point(-2, -3),
            Point(1, -4),
            Point(3, -2),
            Point(2, 1),
            Point(-2, 1)
        ]
        M = computeCenterOfMass(polygon)
        p = Point(0, -3.5)
        wedge = findWedge(polygon, M, p)
        # print('Wedge is ', wedge)
        self.assertTrue(wedge == 0, "Wedge should be 0, instead is " + str(wedge))
    
    def test_wedge_4(self):
        polygon = [
            Point(-2, -3),
            Point(1, -4),
            Point(3, -2),
            Point(2, 1),
            Point(-2, 1)
        ]
        M = computeCenterOfMass(polygon)
        p = Point(-2, -1)
        wedge = findWedge(polygon, M, p)
        # print('Wedge is ', wedge)
        self.assertTrue(wedge == 4, "Wedge should be 4, instead is " + str(wedge))

if __name__ == '__main__':
    unittest.main()
