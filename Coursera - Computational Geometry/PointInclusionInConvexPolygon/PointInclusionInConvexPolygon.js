const eps = 0.00001;
class Point2D {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
}

//return < 0 if tg1 < tg2
function comparePoints(p1, p2, M) {
  return function(p1, p2) {
    const tg1 = (Math.abs(p1.x - M.x) > eps) ? (p1.y - M.y) / (p1.x - M.x) : null;
    const tg2 = (Math.abs(p2.x - M.x) > eps) ? (p2.y - M.y) / (p2.x - M.x) : null;

    if(!tg1 || !tg2) {
      if(Math.abs(p1.x - p2.x) > eps) {
        return p1.x - p2.x;
      } else {
        return p1.y - p2.y;
      }
    }

    if(Math.abs(tg1 - tg2) < eps) {
      return p1.y - p2.y;
    }

    return tg1 - tg2;

  }
}

//Test the compare function
let p1, p2, M;

M = new Point2D(0, -3);
p1 = new Point2D(2, 1);
p2 = new Point2D(-2, 1);

console.log(comparePoints(p1, p2, M)());

function isPointInsidePolygon(p, polygon) {
  const M = new Point2D(
    (polygon[0].x + polygon[1].x + polygon[2].x) / 3,
    (polygon[0].y + polygon[1].y + polygon[2].y) / 3
  );
  const cmp = comparePoints(polygon[0], polygon[1], M);
  cmp(polygon[0], polygon[1]);
  console.log(M);
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

isPointInsidePolygon(points[0], polygon);
