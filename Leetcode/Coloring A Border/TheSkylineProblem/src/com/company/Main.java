package com.company;

public class Main {

    public static void test1() {
        Solution solution = new Solution();

        int n = 5;
        int building[][] = new int[5][];
        building[0] = new int[] {2, 9, 10};
        building[1] = new int[] {3, 7, 15};
        building[2] = new int[] {5, 12, 12};
        building[3] = new int[] {15, 20, 10};
        building[4] = new int[] {19, 24, 8};

        solution.getSkyline(building);
    }

    public static void test2() {
        Solution solution = new Solution();

        int n = 2;
        int building[][] = new int[n][];
        building[0] = new int[] {0, 2, 3};
        building[1] = new int[] {2, 5, 3};


        solution.getSkyline(building);
    }

    public static void test3() {
        Solution solution = new Solution();

        int n = 3;
        int building[][] = new int[n][];
        building[0] = new int[] {1, 2, 1};
        building[1] = new int[] {1, 2, 2};
        building[2] = new int[] {1, 2, 3};


        solution.getSkyline(building);
    }

    public static void main(String[] args) {
	    test1();
	    test2();
        test3();
    }
}
