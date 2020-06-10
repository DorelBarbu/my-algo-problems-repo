const FILL_VALUE = 'x';
const DIRECTIONS_COUNT = 4;
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

var colorBorder = function (grid, r0, c0, color) {
  fill(r0, c0, grid[r0][c0], grid, grid.length, grid[0].length);
};

const isInsideGrid = (x, y, n, m) => 0 <= x && x < n && 0 <= y && y < m;

const fill = function (x, y, target, grid, n, m) {
  if (isInsideGrid(x, y, n, m) && grid[x][y] === target) {
    grid[x][y] = FILL_VALUE;
    for (let i = 0; i < DIRECTIONS_COUNT; i++) {
      fill(x + dx[i], y + dy[i], target, grid, n, m);
    }
  }
};

// Test 1
(function () {
  const r0 = 0;
  const c0 = 0;
  const color = 3;
  const grid = [
    [1, 1],
    [1, 2],
  ];
  colorBorder(grid, r0, c0, color);
  console.log(grid);
})();

// Test 2
(function () {
  const r0 = 0;
  const c0 = 1;
  const color = 3;
  const grid = [
    [1, 2, 2],
    [2, 3, 2],
  ];
  colorBorder(grid, r0, c0, color);
  console.log(grid);
})();
