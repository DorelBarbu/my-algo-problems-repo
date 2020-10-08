BOARD_SIZE = 8


def isInMatrix(x, y, N):
    return 0 <= x and x < N and 0 <= y and y < N

def coordinatesToIndex(x, y, N):
    return x * N + y + 1


totalPossibilities = 0
validPossibilities = 0

def solve(x, y, currentLength, k, path, N):
    global totalPossibilities, validPossibilities

    currIndex = coordinatesToIndex(x, y, N)
    path.append(currIndex)

    if currentLength == k:
        validPossibilities += 1
        return

    for i in range(BOARD_SIZE):
        nextX = x + dx[i]
        nextY = y + dy[i]
        if currentLength < k:
            totalPossibilities += 1
            if isInMatrix(nextX, nextY, N) == True:
                solve(nextX, nextY, currentLength + 1, k, path[0:len(path)], N)


def build3DArray(x, y, z):
    arr = []
    for k in range(x):
        mat = []
        for i in range(y):
            line = []
            for j in range(z):
                line.append(0)
            mat.append(line)
        arr.append(mat)
    return arr


def print3DArray(mat):
    x = len(mat)
    y = len(mat[0])
    for k in range(x):
        for i in range(y):
            print(mat[k][i])
        print('-----')

def solveWithDp(startRow, startCol, targetMoves, N):
    #Fill a 3D array with zeros
    dp = build3DArray(targetMoves + 1, BOARD_SIZE, BOARD_SIZE)
    #Init the base case
    dp[0][startRow][startCol] = 1
    #Fill the DP array

    for k in range(1, targetMoves + 1):
        for x in range(N):
            for y in range(N):
                for p in range(8):
                    nextX = x + dx[p]
                    nextY = y + dy[p]

                    if isInMatrix(nextX, nextY, N):
                        dp[k][nextX][nextY] += dp[k - 1][x][y] / 8.0
    # print3DArray(dp)

    #Extract the answer
    answer = 0
    for x in range(N):
        for y in range(N):
            answer = answer + dp[targetMoves][x][y]
    print("Using dp we got: ", answer)

    return answer



    



        


#Driver program
N = 3
K = 2
r = 0
c = 0
solve(r, c, 0, K, [], N)
print("Total possibilities: ", totalPossibilities)
print("Valid possibilities: ", validPossibilities)
print("Probability: ", validPossibilities * 1.0 / totalPossibilities)

#Dp solution
solveWithDp(r, c, K, N)



