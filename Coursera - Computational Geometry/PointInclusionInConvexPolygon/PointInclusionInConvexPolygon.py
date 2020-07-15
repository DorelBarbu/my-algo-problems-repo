import unittest
import math

EPS = 0.000001

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
def createCmp(M):
  def cmp(p1, p2):
    d = det(M, p2, p1)
    return d if d != 0 else p1.x - p2.x 

  return cmp

def det(a, b, c):
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)


def computeCenterOfMass(polygon):
  return Point((polygon[0].x + polygon[1].x + polygon[2].x) / 3.0, (polygon[0].y + polygon[1].y + polygon[2].y) / 3.0)

# Driver function to solve the problem
def solve(polygon, points):
  M = computeCenterOfMass(polygon)
  

# Determine in which wedge the point p lies.
# pivot is a point from inside the polygon
# polygon represents an array of verticies in counterclockwise order
# Wedge n is given by polygon[n] and polygon[n + 1]
def findWedge(polygon, pivot, p):
  left = 0
  right = len(polygon) - 1
  m = 0
  solution = 0
  while left <= right:
    m = math.floor((left + right) / 2)
    d = det(pivot, polygon[m], p)

    if d == 0:
      break
    if d < 0:
      right = m - 1
      solution = m - 1
      if solution < 0:
        solution = len(polygon) - 1
    else:
      left = m + 1
      solution = m
    

  return solution

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
