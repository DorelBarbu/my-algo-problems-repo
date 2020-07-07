class Point2D {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
}

function isPointInsidePolygon(p, polygon) {
  let M = new Point2D(
    (polygon[0].x + polygon[1].x + polygon[2].x) / 3,
    (polygon[0].y + polygon[1].y + polygon[2].y) / 3
  );
}

//Test 1
const polygon = [
  new Point2D(-2, -3),
  new Point2D(1, -4),
  new Point2D(3, -2),
  new Point2D(2, 1),
  new Point2D(-2, 1),
];

const points = [
  new Point2D(2, -3),
  new Point2D(3, 0),
  new Point2D(0, 0),
  new Point2D(2, -1),
];
