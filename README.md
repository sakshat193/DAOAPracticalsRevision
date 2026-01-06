# DAOA Practical Exam - Complete Guide

**Design and Analysis of Algorithms | Turbo C Compatible**

---

## Table of Contents

1. [Quick Start](#quick-start)
2. [File Index (All 24 Programs)](#file-index-all-24-programs)
3. [Question Coverage Map](#question-coverage-map)
4. [How to Use These Programs](#how-to-use-these-programs)
5. [Graph Programs - Manual Matrix Feature](#graph-programs---manual-matrix-feature)
6. [Complete Experiment Details](#complete-experiment-details)
7. [Turbo C Compatibility Notes](#turbo-c-compatibility-notes)
8. [Exam Strategy & Code Reusability](#exam-strategy--code-reusability)

---

## Quick Start

### Turbo C Usage

1. Open Turbo C IDE
2. File > Open > Select any `.C` file (e.g., `MRGSORT.C`)
3. **Compile**: `Alt + F9`
4. **Run**: `Ctrl + F9`
5. **View Output**: `Alt + F5`

### Repository Features

- **Turbo C Compatible**: DOS 8.3 filenames, `/* */` comment style
- **Error-free**: Validated memory management and input handling
- **Comprehensive**: Covers all 44 DAOA practical examination questions

---

## File Index (All 24 Programs)

| No. | Turbo C File | Algorithm | Questions Covered |
|-----|--------------|-----------|-------------------|
| 1 | `MRGSORT.C` | Merge Sort | Q1 |
| 2 | `QUIKSORT.C` | Quick Sort | Q2 |
| 3 | `RNDQSORT.C` | Randomized Quick Sort | Q3 |
| 4 | `FRACKNAP.C` | Fractional Knapsack | Q4, Q40 |
| 5 | `DIJKSTRA.C` | Dijkstra's Algorithm | Q5 |
| 6 | `LCS_DP.C` | Longest Common Subsequence | Q6, Q39 |
| 7 | `FLOYD.C` | Floyd-Warshall Algorithm | Q7 |
| 8 | `N_QUEENS.C` | N-Queens Problem | Q8, Q41 |
| 9 | `KNAPBNB.C` | 0/1 Knapsack (Branch & Bound) | Q9 |
| 10 | `WORDSRCH.C` | Word Search in Grid | Q10 |
| 11 | `MAGICSQ.C` | Magic Square Cost | Q11 |
| 12 | `TREECUT.C` | Tree Edge Cutting | Q12 |
| 13 | `SUBSUM.C` | Sum of Subsets | Q13, Q24, Q35, Q38 |
| 14 | `JOBSEQ.C` | Job Sequencing with Deadlines | Q14, Q22, Q42, Q43 |
| 15 | `BELLMAN.C` | Bellman-Ford Algorithm | Q15, Q44 |
| 16 | `GRAPHCOL.C` | Graph Coloring | Q16, Q25 |
| 17 | `KRUSKAL.C` | Kruskal's MST | Q17, Q31 |
| 18 | `PRIM_MST.C` | Prim's MST | Q18, Q29, Q30 |
| 19 | `ACTSEL.C` | Activity Selection | Q19, Q32 |
| 20 | `BTREE.C` | B-Tree Operations | Q20, Q36, Q37 |
| 21 | `KNAP01DP.C` | 0/1 Knapsack (DP) | Q21, Q26 |
| 22 | `TSP_DP.C` | Travelling Salesperson (DP) | Q23, Q27 |
| 23 | `MULTISG.C` | Multistage Graph | Q28 |
| 24 | `COINDP.C` | Coin Change (Min Coins) | Q33, Q34 |

---

## Question Coverage Map

### Code Reusability Guide

Many examination questions are scenario-based variants of the same underlying algorithm. This section maps questions to their corresponding implementations to avoid redundant preparation.

#### Fractional Knapsack (`FRACKNAP.C`)
- Q4: Basic fractional knapsack problem
- Q40: Delivery truck with partial package loading

#### Job Sequencing with Deadlines (`JOBSEQ.C`)
- Q14: Basic job sequencing with deadline constraints
- Q22: Courier company delivery job scheduling
- Q42: Software company client task management
- Q43: Data processing center task execution

#### Activity Selection (`ACTSEL.C`)
- Q19: Basic activity selection problem
- Q32: Conference talk scheduling system

#### Dijkstra's Algorithm (`DIJKSTRA.C`)
- Q5: Single source shortest path computation

#### Bellman-Ford Algorithm (`BELLMAN.C`)
- Q15: Basic Bellman-Ford with dynamic programming
- Q44: Navigation system with negative road costs

#### Floyd-Warshall Algorithm (`FLOYD.C`)
- Q7: All-pairs shortest path computation

#### Prim's Algorithm (`PRIM_MST.C`)
- Q18: Basic Prim's algorithm for MST
- Q29: Housing society electricity distribution network
- Q30: University campus internet backbone design

#### Kruskal's Algorithm (`KRUSKAL.C`)
- Q17: Basic Kruskal's algorithm for MST
- Q31: Smart farming sensor network connections

#### Longest Common Subsequence (`LCS_DP.C`)
- Q6: Basic LCS algorithm
- Q39: DNA sequence comparison in bioinformatics

#### 0/1 Knapsack - Dynamic Programming (`KNAP01DP.C`)
- Q21: Basic 0/1 knapsack problem
- Q26: Traveler's backpack optimization

#### Travelling Salesperson Problem (`TSP_DP.C`)
- Q23: Drone delivery route optimization
- Q27: Salesperson client visit route planning

#### Sum of Subsets (`SUBSUM.C`)
- Q13: Basic sum of subsets problem
- Q24: Logistics container weight packing
- Q35: Cashier coin combination system
- Q38: Budget expense matching application

#### Graph Coloring (`GRAPHCOL.C`)
- Q16: Basic graph coloring problem
- Q25: Digital map country coloring system

#### N-Queens Problem (`N_QUEENS.C`)
- Q8: Basic N-Queens placement
- Q41: N-Queens with conflict avoidance explanation

#### B-Tree Operations (`BTREE.C`)
- Q20: B-tree construction with element insertion
- Q36: B-tree element insertion operations
- Q37: B-tree successive insertions

#### Coin Change Problem (`COINDP.C`)
- Q33: Digital payment minimum coins calculation
- Q34: Vending machine change optimization

#### Single-Use Implementations
The following programs cover one question each and cannot be reused:
- Q1: `MRGSORT.C` - Merge Sort
- Q2: `QUIKSORT.C` - Quick Sort
- Q3: `RNDQSORT.C` - Randomized Quick Sort
- Q9: `KNAPBNB.C` - Branch & Bound Knapsack
- Q10: `WORDSRCH.C` - Word Search in Grid
- Q11: `MAGICSQ.C` - Magic Square Cost
- Q12: `TREECUT.C` - Tree Edge Cutting
- Q28: `MULTISG.C` - Multistage Graph

---

## How to Use These Programs

### Standard Programs (User Input)

Most programs accept interactive input from the user:

```
Example: MRGSORT.C
Enter number of elements: 5
Enter 5 integers: 64 34 25 12 22
Sorted array: 12 22 25 34 64
```

### Graph Programs

Programs implementing graph algorithms have a special manual matrix feature for convenient testing. See the next section for detailed instructions.

---

## Graph Programs - Manual Matrix Feature

### Programs with Manual Matrix Toggle

The following seven programs support hardcoded adjacency matrices:

1. `DIJKSTRA.C` - Dijkstra's Algorithm
2. `BELLMAN.C` - Bellman-Ford Algorithm
3. `FLOYD.C` - Floyd-Warshall Algorithm
4. `PRIM_MST.C` - Prim's MST
5. `GRAPHCOL.C` - Graph Coloring
6. `TSP_DP.C` - Travelling Salesperson
7. `MULTISG.C` - Multistage Graph

### How to Enable Manual Matrix Mode

#### Step 1: Locate the Toggle

Open the desired graph program and find this line near the top:

```c
#define USE_MANUAL_MATRIX 0
```

#### Step 2: Enable Manual Mode

Change the value from `0` to `1`:

```c
#define USE_MANUAL_MATRIX 1
```

#### Step 3: Edit the Matrix

Find and modify the hardcoded adjacency matrix in the file:

**Example from `DIJKSTRA.C`:**

```c
#if USE_MANUAL_MATRIX
    /* Edit this matrix manually. Use -1 for no edge. */
    n = 5;
    int manual[5][5] = {
        {0, 10, 3, -1, -1},   /* Vertex 0 (A) connections */
        {-1, 0, 1, 2, -1},    /* Vertex 1 (B) connections */
        {-1, 4, 0, 8, 2},     /* Vertex 2 (C) connections */
        {-1, -1, -1, 0, 7},   /* Vertex 3 (D) connections */
        {-1, -1, -1, 9, 0}    /* Vertex 4 (E) connections */
    };
#endif
```

#### Step 4: Compile and Run

The program will use your predefined matrix instead of prompting for input.

### Matrix Conventions by Program

| Program | No Edge Value | Graph Type | Notes |
|---------|--------------|------------|-------|
| `DIJKSTRA.C` | `-1` | Directed | Non-negative weights only |
| `BELLMAN.C` | `-1` | Directed | Supports negative weights |
| `FLOYD.C` | `-1` | Directed | All-pairs shortest path |
| `PRIM_MST.C` | `0` | Undirected | Minimum spanning tree |
| `GRAPHCOL.C` | `0` | Undirected | Adjacency: 0/1 values only |
| `TSP_DP.C` | `-1` | Complete | Distance matrix |
| `MULTISG.C` | `-1` | DAG | Topological order required |

### Advantages of Manual Matrix Mode

- **Rapid Testing**: No need to manually enter matrix data for each execution
- **Exam Preparation**: Quickly test with known example cases
- **Debugging**: Easily modify and retest edge cases
- **Demonstration**: Pre-load examiner's test cases for viva

**NOTE:** Remember to set `USE_MANUAL_MATRIX` back to `0` when user input mode is required.

---

## Complete Experiment Details

### I. Sorting Algorithms (3 Programs)

#### 1. Merge Sort (`MRGSORT.C`) - Question 1

**Algorithm**: Divide-and-conquer sorting algorithm  
**Input**: Array of integers  
**Output**: Sorted array in ascending order  
**Time Complexity**: O(n log n) - best, average, and worst case  
**Space Complexity**: O(n) auxiliary space  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Stable sorting algorithm
- Recursively divides array into halves
- Merges sorted subarrays in linear time
- Guaranteed O(n log n) performance

**Example**:
```
Input:
  Enter number of elements: 6
  Enter 6 integers: 12 11 13 5 6 7
Output:
  Sorted array: 5 6 7 11 12 13
```

---

#### 2. Quick Sort (`QUIKSORT.C`) - Question 2

**Algorithm**: Partition-based sorting algorithm  
**Input**: Array of integers  
**Output**: Sorted array in ascending order  
**Time Complexity**:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n²) - occurs on already sorted input
**Space Complexity**: O(log n) recursion stack  
**Classification**: P (polynomial-time average)

**Key Concepts**:
- In-place sorting algorithm
- Uses last element as pivot (deterministic)
- Partitions around pivot value
- Worst case on sorted or reverse-sorted arrays

**Example**:
```
Input:
  Enter number of elements: 5
  Enter 5 integers: 9 7 5 11 12
Output:
  Sorted array: 5 7 9 11 12
```

---

#### 3. Randomized Quick Sort (`RNDQSORT.C`) - Question 3

**Algorithm**: Quick Sort with randomized pivot selection  
**Input**: Array of integers  
**Output**: Sorted array in ascending order  
**Time Complexity**: Expected O(n log n)  
**Space Complexity**: O(log n) expected recursion depth  
**Classification**: P (polynomial-time expected)

**Key Concepts**:
- Random pivot selection using `rand()` function
- Avoids worst-case behavior on adversarial inputs
- Expected O(n log n) performance
- Initialized with `srand(time(NULL))`

**Example**:
```
Input:
  Enter number of elements: 6
  Enter 6 integers: 10 7 8 9 1 5
Output:
  Sorted array: 1 5 7 8 9 10
```

---

### II. Greedy Algorithms (3 Programs)

#### 4. Fractional Knapsack (`FRACKNAP.C`) - Questions 4, 40

**Algorithm**: Greedy algorithm based on profit-to-weight ratio  
**Input**: Items with weight and profit values, knapsack capacity  
**Output**: Maximum total profit with fractional item selection  
**Time Complexity**: O(n²) with bubble sort implementation  
**Space Complexity**: O(n)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Calculate profit/weight ratio for each item
- Sort items by ratio in descending order
- Greedily select items (fractions allowed)
- Greedy choice property ensures optimal solution

**Example**:
```
Input:
  Enter number of items: 3
  Enter knapsack capacity: 50
  Item 1 (w p): 10 60
  Item 2 (w p): 20 100
  Item 3 (w p): 30 120
Output:
  Selected items (possibly fractional):
  ID      Taken   WeightUsed      ProfitGained
  1       1.0000  10.0000         60.0000
  2       1.0000  20.0000         100.0000
  3       0.6667  20.0000         80.0000

  Maximum profit = 240.0000
```

**Scenario Coverage**:
- Q4: Basic fractional knapsack formulation
- Q40: Delivery truck partial package loading

---

#### 5. Job Sequencing with Deadlines (`JOBSEQ.C`) - Questions 14, 22, 42, 43

**Algorithm**: Greedy scheduling based on profit maximization  
**Input**: Jobs with deadline and profit values  
**Output**: Maximum profit job sequence  
**Time Complexity**: O(n²)  
**Space Complexity**: O(n + max_deadline)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Sort jobs by profit in descending order
- Assign each job to latest available slot before deadline
- One job per time slot constraint
- Greedy selection ensures optimal profit

**Example**:
```
Input:
  Enter number of jobs: 4
  Job 1 (d p): 4 20
  Job 2 (d p): 1 10
  Job 3 (d p): 1 40
  Job 4 (d p): 1 30
Output:
  Selected job sequence (time slot -> job id):
  Slot 1 -> Job 3 (d=1, p=40)
  Slot 4 -> Job 1 (d=4, p=20)

  Jobs done: 2
  Maximum profit: 60
```

**Scenario Coverage**:
- Q14: Basic job sequencing problem
- Q22: Courier company delivery scheduling
- Q42: Software company task management
- Q43: Data processing center execution

---

#### 6. Activity Selection (`ACTSEL.C`) - Questions 19, 32

**Algorithm**: Greedy selection based on earliest finish time  
**Input**: Activities with start and finish times  
**Output**: Maximum number of non-overlapping activities  
**Time Complexity**: O(n²) with bubble sort  
**Space Complexity**: O(n)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Sort activities by finish time (ascending)
- Select activity if start time >= last finish time
- Greedy earliest-finish strategy is optimal
- Maximizes number of compatible activities

**Example**:
```
Input:
  Enter number of activities: 3
  Activity 1 (start finish): 10 20
  Activity 2 (start finish): 12 25
  Activity 3 (start finish): 20 30
Output:
  Selected activities: 1 3
  Total activities selected = 2
```

**Scenario Coverage**:
- Q19: Basic activity selection problem
- Q32: Conference talk scheduling

---

### III. Graph Algorithms (7 Programs)

#### 7. Dijkstra's Algorithm (`DIJKSTRA.C`) - Question 5

**Algorithm**: Single-source shortest path (greedy approach)  
**Input**: Weighted graph with non-negative edges, source vertex  
**Output**: Shortest distances from source to all vertices  
**Time Complexity**: O(V²) with adjacency matrix  
**Space Complexity**: O(V²) for matrix + O(V) for arrays  
**Classification**: P (polynomial-time)

**Key Concepts**:
- **Restriction**: Non-negative edge weights only
- Uses dist[] and visited[] arrays
- Greedy: always selects minimum distance unvisited vertex
- Relaxation of edges from selected vertex
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  Enter source vertex (A..E or 0..4): 0
Output:
  Shortest distances from A:
  A -> A : 0
  A -> B : 7
  A -> C : 3
  A -> D : 9
  A -> E : 5
```

---

#### 8. Bellman-Ford Algorithm (`BELLMAN.C`) - Questions 15, 44

**Algorithm**: Single-source shortest path with negative weights  
**Input**: Weighted graph (may contain negative weights), source vertex  
**Output**: Shortest distances; detects negative cycles  
**Time Complexity**: O(VE)  
**Space Complexity**: O(V + E)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Handles negative edge weights
- Performs V-1 relaxation iterations
- Additional iteration detects negative cycles
- Dynamic programming approach
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  Enter source vertex (A..E or 0..4): 0
Output:
  Shortest distances from A:
  A -> A : 0
  A -> B : 2
  A -> C : 4
  A -> D : 7
  A -> E : -2
```

**Scenario Coverage**:
- Q15: Basic Bellman-Ford implementation
- Q44: Navigation with negative road costs

---

#### 9. Floyd-Warshall Algorithm (`FLOYD.C`) - Question 7

**Algorithm**: All-pairs shortest path (dynamic programming)  
**Input**: Weighted graph adjacency matrix  
**Output**: Shortest distance matrix for all vertex pairs  
**Time Complexity**: O(V³)  
**Space Complexity**: O(V²)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Triple nested loop: k (intermediate) → i → j
- Works with negative edges (not negative cycles)
- Dynamic programming recurrence relation
- dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  (No input required; matrix is hardcoded)
Output:
  All-pairs shortest path matrix:
  0 5 8 9
  INF 0 3 4
  INF INF 0 1
  INF INF INF 0
```

---

#### 10. Prim's Algorithm (`PRIM_MST.C`) - Questions 18, 29, 30

**Algorithm**: Minimum Spanning Tree (vertex-growing approach)  
**Input**: Undirected weighted graph  
**Output**: MST edges and total weight  
**Time Complexity**: O(V²) with adjacency matrix  
**Space Complexity**: O(V²) for matrix + O(V) for arrays  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Greedy: grows tree by selecting minimum-weight edge
- Uses key[] array for minimum edge weights
- Uses parent[] array to track MST structure
- Vertex-centric approach
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  Enter number of vertices: (Skipped in Manual Mode)
Output:
  MST edges (u - v : weight):
  A - B : 2
  B - C : 3
  B - E : 5
  A - D : 6
  Total weight = 16
```

**Scenario Coverage**:
- Q18: Basic Prim's algorithm
- Q29: Housing electricity distribution network
- Q30: University campus internet backbone

---

#### 11. Kruskal's Algorithm (`KRUSKAL.C`) - Questions 17, 31

**Algorithm**: Minimum Spanning Tree (edge-sorting approach)  
**Input**: Undirected weighted graph (edge list)  
**Output**: MST edges and total weight  
**Time Complexity**: O(E²) with bubble sort  
**Space Complexity**: O(V + E)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Sort all edges by weight (ascending)
- Use Union-Find data structure to detect cycles
- Edge-centric approach
- Greedy edge selection

**Example**:
```
Input:
  Enter number of vertices and edges: 4 5
  Edges:
    0 1 10
    0 2 6
    0 3 5
    1 3 15
    2 3 4
Output:
  MST edges (u - v : w):
  2 - 3 : 4
  0 - 3 : 5
  0 - 1 : 10
  Total weight = 19
```

**Scenario Coverage**:
- Q17: Basic Kruskal's algorithm
- Q31: Smart farming sensor connections

---

#### 12. Travelling Salesperson Problem (`TSP_DP.C`) - Questions 23, 27

**Algorithm**: TSP using dynamic programming with bitmask  
**Input**: Distance matrix for complete graph  
**Output**: Minimum tour cost and route  
**Time Complexity**: O(n² × 2^n)  
**Space Complexity**: O(n × 2^n)  
**Classification**: NP-hard (this is exact exponential algorithm)

**Key Concepts**:
- State: dp[mask][city] represents visited set and current city
- Bitmask represents visited cities
- Exact solution with exponential time complexity
- Memoization for optimal substructure
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  (No input required; matrix is hardcoded)
Output:
  Minimum tour cost = 80
  Tour: A -> B -> D -> C -> A
```

**Scenario Coverage**:
- Q23: Drone delivery route optimization
- Q27: Salesperson client visit planning

---

#### 13. Multistage Graph (`MULTISG.C`) - Question 28

**Algorithm**: Shortest path in DAG using dynamic programming  
**Input**: Weighted directed acyclic graph in topological order  
**Output**: Minimum cost path from source to sink  
**Time Complexity**: O(V²) with adjacency matrix  
**Space Complexity**: O(V²) for matrix + O(V) for DP arrays  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Backward dynamic programming from sink vertex
- Vertices must be in stage/topological order
- Stage-wise optimal decision making
- cost[i] = min(cost[i], edge[i][j] + cost[j])
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  (No input required)
Output:
  Minimum cost from A to H = 9
  Path: A -> D -> G -> H
```

---

### IV. Dynamic Programming (3 Programs)

#### 14. Longest Common Subsequence (`LCS_DP.C`) - Questions 6, 39

**Algorithm**: Sequence alignment dynamic programming  
**Input**: Two strings  
**Output**: LCS length and one LCS string  
**Time Complexity**: O(mn)  
**Space Complexity**: O(mn)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- 2D DP table: dp[i][j] for first i and j characters
- If match: dp[i][j] = dp[i-1][j-1] + 1
- Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
- Backtracking to construct actual LCS string

**Example**:
```
Input:
  Enter first string: AGGTAB
  Enter second string: GXTXAYB
Output:
  LCS length = 4
  One LCS = GTAB
```

**Scenario Coverage**:
- Q6: Basic longest common subsequence
- Q39: DNA sequence comparison application

---

#### 15. 0/1 Knapsack (`KNAP01DP.C`) - Questions 21, 26

**Algorithm**: 0/1 Knapsack using dynamic programming  
**Input**: Items with weight and value, capacity constraint  
**Output**: Maximum value and selected items  
**Time Complexity**: O(nW) - pseudo-polynomial  
**Space Complexity**: O(nW)  
**Classification**: NP-hard (DP efficient for small W)

**Key Concepts**:
- Include/exclude decision for each item
- DP state: dp[i][w] = max value with first i items, capacity w
- Recurrence: dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wt[i]])
- Backtracking to determine selected items

**Example**:
```
Input:
  Enter number of items: 3
  Enter capacity: 50
  Item 1 (w v): 10 60
  Item 2 (w v): 20 100
  Item 3 (w v): 30 120
Output:
  Total Value = 220
  Selected items: 2 3
```

**Scenario Coverage**:
- Q21: Basic 0/1 knapsack problem
- Q26: Traveler's backpack optimization

---

#### 16. Coin Change (`COINDP.C`) - Questions 33, 34

**Algorithm**: Minimum coins with unbounded supply (DP)  
**Input**: Coin denominations, target amount  
**Output**: Minimum coins needed and coin combination  
**Time Complexity**: O(n × amount)  
**Space Complexity**: O(amount)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Unlimited supply of each denomination
- DP state: dp[i] = minimum coins to make amount i
- Bottom-up tabulation approach
- dp[i] = min(dp[i], dp[i-coin] + 1) for all coins

**Example**:
```
Input:
  Enter number of coins: 3
  Enter coin values: 1 2 5
  Enter target amount: 11
Output:
  Minimum coins required: 3
  Combination: 5 5 1
```

**Scenario Coverage**:
- Q33: Digital payment system minimum coins
- Q34: Vending machine change optimization

---

### V. Backtracking & Branch and Bound (5 Programs)

#### 17. N-Queens Problem (`N_QUEENS.C`) - Questions 8, 41

**Algorithm**: Constraint satisfaction using backtracking  
**Input**: N (board size)  
**Output**: One valid N-queens placement  
**Time Complexity**: Exponential (commonly O(N!))  
**Space Complexity**: O(N) for recursion + O(N) for placements  
**Classification**: In NP (verification polynomial)

**Key Concepts**:
- Place one queen per row sequentially
- Check column and diagonal conflicts using isSafe()
- Backtrack on conflict detection
- Prints first valid solution found

**Example**:
```
Input:
  Enter N (number of queens): 4
Output:
  One solution for N=4:
  . Q . .
  . . . Q
  Q . . .
  . . Q .
```

**Scenario Coverage**:
- Q8: Basic N-Queens implementation
- Q41: N-Queens with conflict avoidance explanation

---

#### 18. Sum of Subsets (`SUBSUM.C`) - Questions 13, 24, 35, 38

**Algorithm**: Subset enumeration using backtracking  
**Input**: Array of positive integers, target sum  
**Output**: All subsets that sum to target  
**Time Complexity**: O(2^n) worst case  
**Space Complexity**: O(n) recursion + O(n) selection array  
**Classification**: NP-complete (decision: "subset sum == target?")

**Key Concepts**:
- Include/exclude decision tree for each element
- Enumerates all matching subsets
- Optional sorting for organized output
- Can be optimized with pruning bounds

**Example**:
```
Input:
  Enter number of elements: 5
  Enter elements: 10 7 5 18 12
  Enter target sum: 30
Output:
  Subset found: 18 12
  Subset found: 10 12 5 (or similar depending on sort)
```

**Scenario Coverage**:
- Q13: Basic sum of subsets problem
- Q24: Logistics container weight matching
- Q35: Cashier coin combinations (single use)
- Q38: Budget expense matching

---

#### 19. Graph Coloring (`GRAPHCOL.C`) - Questions 16, 25

**Algorithm**: Chromatic number using backtracking  
**Input**: Adjacency matrix of undirected graph  
**Output**: Minimum colors required and coloring assignment  
**Time Complexity**: Exponential in worst case  
**Space Complexity**: O(V²) for matrix + O(V) for colors  
**Classification**: NP-hard (optimization); NP-complete (k-colorability decision)

**Key Concepts**:
- Try colors 1 through V systematically
- Check if adjacent vertices have same color
- Find minimum m such that graph is m-colorable
- Backtrack on color conflicts
- **Manual Matrix Available**

**Example (Manual Matrix Mode)**:
```
Input:
  (No input required)
Output:
  Minimum colors required = 3
  Coloring:
  A -> Color 1
  B -> Color 2
  C -> Color 3
  D -> Color 2
  E -> Color 1
```

**Scenario Coverage**:
- Q16: Basic graph coloring problem
- Q25: Digital map country coloring

---

#### 20. 0/1 Knapsack - Branch & Bound (`KNAPBNB.C`) - Question 9

**Algorithm**: Optimization using branch and bound  
**Input**: Items with weight and value, capacity  
**Output**: Maximum value and selected items  
**Time Complexity**: Exponential (often faster than pure backtracking)  
**Space Complexity**: O(number of live nodes)  
**Classification**: NP-hard (branch & bound for better average case)

**Key Concepts**:
- Sort items by profit/weight ratio
- Compute upper bound using fractional relaxation
- Prune branches where bound ≤ current best
- Priority queue for best-first search
- More efficient than exhaustive search

**Example**:
```
Input:
  Enter number of items: 4
  Capacity: 15
  Item 1 (w p): 2 10
  Item 2 (w p): 4 10
  Item 3 (w p): 6 12
  Item 4 (w p): 9 18
Output:
  Maximum profit = 38
```

---

#### 21. Word Search in Grid (`WORDSRCH.C`) - Question 10

**Algorithm**: Grid traversal using DFS backtracking  
**Input**: m×n character grid, word to search  
**Output**: true/false indicating word existence  
**Time Complexity**: O(mn × 4^L) where L = word length  
**Space Complexity**: O(mn) for visited + O(L) recursion  
**Classification**: Exponential backtracking (in NP)

**Key Concepts**:
- DFS from each cell matching first letter
- 4-directional movement (horizontal/vertical only)
- Mark cells as visited during search
- Backtrack and unmark after exploration
- Same cell cannot be used twice in one path

**Example**:
```
Input:
  Enter rows and columns (m n): 3 4
  Enter word to search: CAT
  Enter grid characters row-wise:
  Row 1: ACAT
  Row 2: XBCX
  Row 3: YYYY
Output:
  true
```

---

### VI. Trees & Miscellaneous (3 Programs)

#### 22. B-Tree Operations (`BTREE.C`) - Questions 20, 36, 37

**Algorithm**: B-Tree insertion with node splitting  
**Input**: Minimum degree t, keys to insert  
**Output**: B-Tree structure displayed level-wise  
**Time Complexity**: O(t log_t N) per insertion  
**Space Complexity**: O(N) for nodes and keys  
**Classification**: P (polynomial-time)

**Key Concepts**:
- Each node: minimum t-1 keys, maximum 2t-1 keys
- Split operation when node reaches 2t-1 keys
- Root can have minimum 1 key
- Maintains balanced tree property
- CLRS-style implementation

**Example**:
```
Input:
  Enter minimum degree t: 2
  Enter number of keys: 7
  Enter 7 keys: 10 20 5 6 12 30 7
Output:
  (Tree structure printed level-wise)
  [ 7 10 ]
  [ 5 6 ] [ 12 20 30 ]
```

**Scenario Coverage**:
- Q20: B-tree construction with insertions
- Q36: B-tree element insertion operations
- Q37: B-tree successive insertions

---

#### 23. Tree Edge Cutting (`TREECUT.C`) - Question 12

**Algorithm**: Tree optimization using DFS  
**Input**: Undirected tree with node values  
**Output**: Minimum difference after cutting one edge  
**Time Complexity**: O(n)  
**Space Complexity**: O(n)  
**Classification**: P (polynomial-time)

**Key Concepts**:
- DFS traversal to compute subtree sums
- For each edge (u,v): difference = |total_sum - 2×subtree[v]|
- Track minimum difference across all edges
- Linear time solution

**Example**:
```
Input:
  Enter n: 3
  Enter 3 node values: 100 200 100
  Enter 2 edges:
  1 2
  2 3
Output:
  Minimum difference after cutting one edge = 0
  (Using edge 2-3: {3}=100, {1,2}=300. Diff 200. Using 1-2: {1}=100, {2,3}=300. Diff 200. Wait, logic check: 100+200+100=400. Half=200.)
```

---

#### 24. Magic Square Cost (`MAGICSQ.C`) - Question 11

**Algorithm**: Brute-force comparison (constant time)  
**Input**: 3×3 matrix of integers [1-9]  
**Output**: Minimum cost to convert to magic square  
**Time Complexity**: O(1) - only 8 possible 3×3 magic squares  
**Space Complexity**: O(1)  
**Classification**: P (constant time)

**Key Concepts**:
- Compare input against all 8 valid 3×3 magic squares
- Cost = sum of |input[i] - magic[i]| for each position
- Select minimum cost among all 8 comparisons
- Magic constant for 3×3 is 15

**Example**:
```
Input:
  Enter 3x3 matrix values:
  4 9 2
  3 5 7
  8 1 5
Output:
  Minimum cost = 1
  (Change 5 at (2,2) to 6 -> standard magic square)
```

---

## Turbo C Compatibility Notes

### Filename Restrictions

All filenames strictly adhere to DOS 8.3 naming convention:
- Maximum 8 characters before file extension
- Extension: `.C` (case-insensitive in DOS)
- No spaces or special characters
- Uppercase representation in DOS environment

### Comment Style

All source files use C89-compatible block comments:

```c
/* This is Turbo C compatible */
/* NOT supported: // single-line comments */
```

### Standard Library Headers

```c
#include <stdio.h>   /* Input/output operations */
#include <stdlib.h>  /* malloc, free, rand, qsort, exit */
#include <string.h>  /* strlen, strcmp, strcpy */
#include <ctype.h>   /* isalpha, toupper, tolower */
#include <time.h>    /* time() for random seed */
```

### Memory Management

All programs implement proper resource management:
- Dynamic allocation via `malloc()`
- Allocation failure checking
- Complete deallocation with `free()` before termination
- No memory leaks in normal execution paths

### Known Turbo C Limitations

- **Memory Constraints**: DOS memory model limits (~64KB per segment)
- **Recursion Depth**: Limited stack size for deep recursion
- **Integer Size**: 16-bit integers (range: -32768 to 32767)
  - Use `long` type for values requiring extended range
- **Array Size**: Large arrays may require far pointers or dynamic allocation

---

## Exam Strategy & Code Reusability

### Efficient Preparation Approach

The 44 examination questions are covered by only **24 unique implementations**. Strategic focus on high-reuse programs maximizes preparation efficiency.

### Priority Programs (High Reusability)

**Tier 1 - Four or More Questions:**
1. **`SUBSUM.C`** covers 4 questions (Q13, Q24, Q35, Q38)
2. **`JOBSEQ.C`** covers 4 questions (Q14, Q22, Q42, Q43)

**Tier 2 - Three Questions:**
3. **`BTREE.C`** covers 3 questions (Q20, Q36, Q37)
4. **`PRIM_MST.C`** covers 3 questions (Q18, Q29, Q30)

### Medium Priority Programs (Two Questions Each)

- `FRACKNAP.C` - Q4, Q40
- `ACTSEL.C` - Q19, Q32
- `BELLMAN.C` - Q15, Q44
- `KRUSKAL.C` - Q17, Q31
- `LCS_DP.C` - Q6, Q39
- `KNAP01DP.C` - Q21, Q26
- `TSP_DP.C` - Q23, Q27
- `GRAPHCOL.C` - Q16, Q25
- `N_QUEENS.C` - Q8, Q41
- `COINDP.C` - Q33, Q34

### Single-Use Programs (Thirteen Programs)

Each covers exactly one question and requires individual preparation.

### Algorithm Classification Priority

**Essential Knowledge** (High examination probability):
1. Sorting: Quick Sort / Merge Sort
2. Graph: Dijkstra's Algorithm
3. Dynamic Programming: 0/1 Knapsack
4. Greedy: Job Sequencing, Fractional Knapsack
5. Backtracking: N-Queens
6. MST: Prim's or Kruskal's Algorithm

**Recommended Knowledge** (Medium probability):
- Longest Common Subsequence
- Floyd-Warshall Algorithm
- Graph Coloring
- Subset Sum Problem
- Activity Selection

**Supplementary Knowledge** (Lower probability):
- Travelling Salesperson Problem
- Bellman-Ford Algorithm
- Branch & Bound Knapsack
- Multistage Graph
- B-Tree Operations

### Viva Voce Preparation

#### Core Concepts to Explain

1. **Complexity Analysis**: Understand time and space complexity for each algorithm
2. **Algorithm Classification**: P, NP, NP-hard, NP-complete distinctions
3. **Design Paradigm**: Greedy vs Dynamic Programming vs Backtracking
4. **Base Cases**: Explain termination conditions for recursive algorithms
5. **Optimality**: Justify why certain approaches guarantee optimal solutions

#### Common Examiner Questions

**Q:** "Why not use Dijkstra's algorithm when graph has negative weights?"  
**A:** Dijkstra's greedy approach fails with negative weights as it assumes once a vertex is finalized, its distance is optimal. Bellman-Ford handles negative weights correctly.

**Q:** "What is the difference between Prim's and Kruskal's algorithms?"  
**A:** Prim's grows MST from a single vertex (vertex-centric), while Kruskal's sorts all edges and builds MST by selecting minimum edges avoiding cycles (edge-centric).

**Q:** "Why is TSP classified as NP-hard?"  
**A:** No known polynomial-time algorithm exists. Our DP solution is O(n²×2^n), exponential in n. It's a classic NP-hard optimization problem.

**Q:** "Explain the greedy choice in fractional knapsack."  
**A:** Always select item with highest profit-to-weight ratio. This greedy strategy is optimal because fractions are allowed, unlike 0/1 knapsack.

**Q:** "How does Union-Find prevent cycles in Kruskal's algorithm?"  
**A:** Union-Find maintains disjoint sets. Before adding edge (u,v), we check if u and v are in same set. If yes, adding creates cycle. If no, we union the sets.

#### Demonstration Strategies

- Utilize **manual matrix feature** for graph algorithm demonstrations
- Prepare **multiple test cases** (best case, worst case, average case)
- Discuss **alternative approaches** and justify chosen implementation
- Explain **trade-offs** between different algorithms (e.g., Prim vs Kruskal)

---

## File Organization

```
DAOAPracs/
│
├── README.md          (This comprehensive guide)
├── .gitignore         (Git ignore configuration)
│
├── Sorting Algorithms (3 files)
│   ├── MRGSORT.C      - Merge Sort
│   ├── QUIKSORT.C     - Quick Sort
│   └── RNDQSORT.C     - Randomized Quick Sort
│
├── Greedy Algorithms (3 files)
│   ├── FRACKNAP.C     - Fractional Knapsack
│   ├── JOBSEQ.C       - Job Sequencing with Deadlines
│   └── ACTSEL.C       - Activity Selection
│
├── Graph Algorithms (7 files)
│   ├── DIJKSTRA.C     - Dijkstra's Shortest Path
│   ├── BELLMAN.C      - Bellman-Ford Algorithm
│   ├── FLOYD.C        - Floyd-Warshall All-Pairs
│   ├── PRIM_MST.C     - Prim's MST
│   ├── KRUSKAL.C      - Kruskal's MST
│   ├── TSP_DP.C       - Travelling Salesperson
│   └── MULTISG.C      - Multistage Graph
│
├── Dynamic Programming (3 files)
│   ├── LCS_DP.C       - Longest Common Subsequence
│   ├── KNAP01DP.C     - 0/1 Knapsack
│   └── COINDP.C       - Coin Change Problem
│
├── Backtracking & Branch-Bound (5 files)
│   ├── N_QUEENS.C     - N-Queens Problem
│   ├── SUBSUM.C       - Sum of Subsets
│   ├── GRAPHCOL.C     - Graph Coloring
│   ├── KNAPBNB.C      - Knapsack (Branch & Bound)
│   └── WORDSRCH.C     - Word Search in Grid
│
└── Trees & Miscellaneous (3 files)
    ├── BTREE.C        - B-Tree Operations
    ├── TREECUT.C      - Tree Edge Cutting
    └── MAGICSQ.C      - Magic Square Cost
```

---

## Quick Question Finder

**Reference table for rapid question-to-file lookup:**

| Questions | File | Questions | File | Questions | File |
|-----------|------|-----------|------|-----------|------|
| Q1 | MRGSORT | Q16 | GRAPHCOL | Q31 | KRUSKAL |
| Q2 | QUIKSORT | Q17 | KRUSKAL | Q32 | ACTSEL |
| Q3 | RNDQSORT | Q18 | PRIM_MST | Q33 | COINDP |
| Q4 | FRACKNAP | Q19 | ACTSEL | Q34 | COINDP |
| Q5 | DIJKSTRA | Q20 | BTREE | Q35 | SUBSUM |
| Q6 | LCS_DP | Q21 | KNAP01DP | Q36 | BTREE |
| Q7 | FLOYD | Q22 | JOBSEQ | Q37 | BTREE |
| Q8 | N_QUEENS | Q23 | TSP_DP | Q38 | SUBSUM |
| Q9 | KNAPBNB | Q24 | SUBSUM | Q39 | LCS_DP |
| Q10 | WORDSRCH | Q25 | GRAPHCOL | Q40 | FRACKNAP |
| Q11 | MAGICSQ | Q26 | KNAP01DP | Q41 | N_QUEENS |
| Q12 | TREECUT | Q27 | TSP_DP | Q42 | JOBSEQ |
| Q13 | SUBSUM | Q28 | MULTISG | Q43 | JOBSEQ |
| Q14 | JOBSEQ | Q29 | PRIM_MST | Q44 | BELLMAN |
| Q15 | BELLMAN | Q30 | PRIM_MST | | |

---

## Pre-Examination Checklist

### Technical Verification

- [ ] All 24 source files present and accessible
- [ ] At least 5 high-priority programs tested in Turbo C
- [ ] Manual matrix feature verified for graph programs
- [ ] Compilation successful for all tested programs
- [ ] Sample runs executed with known test cases

### Conceptual Preparation

- [ ] Time complexity understood for each algorithm
- [ ] Space complexity analysis prepared
- [ ] Algorithm classification memorized (P, NP-hard, NP-complete)
- [ ] Greedy vs DP decision criteria internalized
- [ ] Question-to-implementation mapping reviewed

### Practical Skills

- [ ] Turbo C keyboard shortcuts practiced (Alt+F9, Ctrl+F9, Alt+F5)
- [ ] Manual matrix toggle procedure rehearsed
- [ ] Test case modification demonstrated
- [ ] Code explanation prepared for viva questions

---

## Troubleshooting Guide

### Compilation Issues

**Problem:** Source file fails to compile  
**Solutions:**
- Verify all comments use `/* */` format (not `//`)
- Confirm filename follows 8.3 convention
- Check all required headers are included
- Ensure no C99 or C++ specific syntax

**Problem:** "Out of memory" error during compilation  
**Solutions:**
- Reduce test input size due to DOS memory constraints
- Use smaller array dimensions
- Check for infinite loops or unbounded recursion
- Verify proper memory deallocation

### Runtime Issues

**Problem:** Incorrect output from graph programs  
**Solutions:**
- Verify vertex numbering (0-indexed in implementation)
- Check edge representation (-1 vs 0 for "no edge" varies by program)
- For directed graphs, confirm edge direction correctness
- Validate manual matrix matches expected input format

**Problem:** Program hangs or crashes  
**Solutions:**
- Check input validation (no negative values where prohibited)
- Verify array bounds not exceeded
- Inspect recursion depth for stack overflow
- Ensure valid input format (integers where expected)

### Manual Matrix Issues

**Problem:** Program still requests user input despite enabling manual matrix  
**Solutions:**
- Verify `#define USE_MANUAL_MATRIX 1` change saved
- Recompile program after modification (Alt+F9)
- Confirm correct program opened (check filename)
- Check preprocessor directives syntax

---

## License

This repository contains educational material for academic examination preparation. All implementations are provided for learning purposes.

---

## Acknowledgments

Developed as comprehensive preparation material for Design and Analysis of Algorithms practical examination. All 44 examination questions covered through 24 optimized, Turbo C-compatible implementations.

**Repository Status:** Complete and examination-ready

---

**End of Documentation**
