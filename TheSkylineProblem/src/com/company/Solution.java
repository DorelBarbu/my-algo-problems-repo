package com.company;

import java.util.*;

class Solution {
    private static enum pointType {END, START}

    ;

    private static class Point {
        public int x;
        public int y;
        public int b;
        public pointType t;

        public Point(int x, int y, int b, pointType t) {
            this.x = x;
            this.y = y;
            this.b = b;
            this.t = t;
        }

        public String toString() {
            return "x = " + x + " y = " + y;
        }
    }

    private List<Point> criticalPoints;

    /*Step 1: build the critical points list*/
    private void buildCriticalPointsList(int[][] buildings) {
        criticalPoints = new ArrayList<>();
        for (int i = 0; i < buildings.length; i++) {
            int[] building = buildings[i];
            criticalPoints.add(new Point(building[0], building[2], i, pointType.START));
            criticalPoints.add(new Point(building[1], building[2], i, pointType.END));
        }
    }

    private List<List<Integer>> sweep(List<Point> criticalPoints) {
        //System.out.println(criticalPoints.toString());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(p -> -p));
        int[] criticalPointHeights = new int[criticalPoints.size()];
        List<List<Integer>> solution = new ArrayList<>();
        int prevHeight = 0;
        pq.offer(0);
        for (int i = 0; i < criticalPoints.size(); ) {
            Point p = criticalPoints.get(i);
            int currHeight;
            if (p.t == pointType.START) {
                pq.offer(p.y);
//                currHeight = pq.peek();
            } else {
//                currHeight = pq.peek();
                pq.remove(p.y);
            }

            List<Integer> pct = new ArrayList<>();

            currHeight = pq.peek();

            //System.out.print(currHeight + " ");
            if (currHeight != prevHeight) {
                pct.add(criticalPoints.get(i).x);
                pct.add(currHeight);
                prevHeight = currHeight;
                solution.add(pct);
            }


            i++;
        }
        //System.out.print("\n");
        //System.out.println(solution.toString());
        return solution;
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> solution = new ArrayList<>();
        /*Step 1: Build the list of critical points*/
        buildCriticalPointsList(buildings);
        /*Step 2: Sort it by the x coordinate*/
        Collections.sort(criticalPoints, (p1, p2) -> {
            if(p1.x != p2.x)
                return p1.x - p2.x;
            else {
                //If they have the same type, the start point comes first
                if(p1.t != p2.t) {
                    return p1.t == pointType.START ? -1 : 1;
                } else {
                    //If both are start points, the biggest height first
                    if(p1.t == pointType.START) {
                        return p2.y - p1.y;
                    } else {
                        //If both are end points, the smallest height first
                        return p1.y - p2.y;
                    }
                }
            }
        });
//        System.out.println(criticalPoints.toString());
        /*Step 3: Use a sweep line in order to get the solution of the problem */
        return sweep(criticalPoints);
//        for(int i = 0; i < h.length; i++) {
//            System.out.print(h[i] + " ");
//        }
//        System.out.print("\n");
        /*Step 4: Build the problem solution */
    }
}