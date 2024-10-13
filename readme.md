for sudoku problems https://sudoku-api.vercel.app/api/dosuku

Time Complexity:
Best Case: O(N) - Few placements needed before finding a solution.
Average Case: O(N^2) or O(N^2 \cdot d) - Moderate number of initial clues leads to some backtracking but is generally efficient.
Average Case: O(9^(N²)) - The worst-case scenario arises when the algorithm must explore nearly all possible placements for each empty cell. This can happen with puzzles that have very few clues and require extensive backtracking to arrive at a solution. Each cell has 9 possibilities (1 through 9), leading to an exponential growth in the number of configurations to explore.

Space Complexity: O(N^2)

the

    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    works in a way thet lets say my row in 7,0 so that will be the last gird in first column
    so the starting row value will be (7/3) * 3 = 6
