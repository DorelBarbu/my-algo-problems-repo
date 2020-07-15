import unittest

EPS = 0.000001
M = None

def eq(x, y):
  return abs(x - y) < EPS

def neq(x, y):
  return not eq(x, y)

class Point:
  def __init__(self, x, y):
    self.x = x
    self.y = y
  
  def __str__(self):
    return "(" + str(self.x) + " ," + str(self.y) + ")"


# If p1 < p2 return something negative. Else return something positive.
def cmp(p1, p2):
  tg1 = (p1.x - M.x) / (p1.y - M.y) if neq(p1.y, M.y) else None
  tg2 = (p2.x - M.x) / (p2.y - M.y) if neq(p2.y, M.y) else None

  if tg1 and tg2:
    return tg1 - tg2

  return p1.x - p2.x if neq(p1.x, p2.x) else p1.y - p2.y


def computeCenterOfMass(polygon):
  return Point((polygon[0].x + polygon[1].x + polygon[2].x) / 3.0, (polygon[0].y + polygon[1].y + polygon[2].y) / 3.0)

# Driver function to solve the problem
def solve(polygon, points):
  global M
  M = computeCenterOfMass(polygon)
  


#Test 1

polygon = [
  Point(-2, -3),
  Point(1, -4),
  Point(3, -2),
  Point(2, 1),
  Point(-2, 1)
]

points = [
  Point(2, -3),
  Point(3, 0),
  Point(0, 0),
  Point(2, -1)
]

#solve(polygon, points)

x = -1
assert x >= 0, "Should be >= 0"