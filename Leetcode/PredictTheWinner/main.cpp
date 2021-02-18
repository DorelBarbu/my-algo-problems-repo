#define INPUT_FILE "date.in"
#define OUTPUT_FILE "date.out"
#define MAXN 20

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream in(INPUT_FILE);
ofstream out(OUTPUT_FILE);

int dp[MAXN][MAXN][MAXN];
int spart[MAXN];

int sumBetween(int start, int end) {
  return start > 0 ? spart[end] - spart[start - 1] : spart[end];
}

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        //Base case
        for(int i = 0; i < n; i++) {
          dp[n - 1][i][i] = nums[i];
          spart[i] = (i > 0 ? spart[i - 1] + nums[i] : nums[i]);
        }
        //Fill the dp matrix
        for(int m = n - 2; m >= 0; m--) {
          for(int s = 0; s < n - 1; s++) {
            for(int e = s + 1; e < n; e++) {
              if(dp[m + 1][s + 1][e] < dp[m + 1][s][e - 1]) {
                dp[m][s][e] = sumBetween(s, e) - dp[m + 1][s + 1][e];
              } else {
                dp[m][s][e] = sumBetween(s, e) - dp[m + 1][s][e - 1];
              }
            }
          }
        }
        
        int firstPlayerScore = dp[0][0][n - 1];
        int secondPlayerScore = spart[n - 1] - firstPlayerScore;

        return firstPlayerScore >= secondPlayerScore;
    }
};


void test1() {
  cout<<"test1"<<endl;
  vector<int> nums = vector<int>();
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(2);
  Solution s = Solution();
  s.PredictTheWinner(nums);
  cout<<endl;
}

void test2() {
  cout<<"test2"<<endl;
  vector<int> nums = vector<int>();
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(233);
  nums.push_back(7);
  Solution s = Solution();
  s.PredictTheWinner(nums);
  cout<<endl;
}

int main() {
  test1();
  test2();
  return 0;
}