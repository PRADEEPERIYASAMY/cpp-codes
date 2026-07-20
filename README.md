# C++ DSA Practice

A comprehensive collection of Data Structures and Algorithms problems solved in C++, 
built incrementally across **100+ commits** during my early, focused DSA practice 
phase (March–April 2022). This predates my transition to LeetCode — see 
[Current Practice](#-current-practice) below for the full timeline.

## What's Actually in Here — Problem Analysis

This isn't a shallow "hello world" DSA repo — it spans a genuinely wide range of 
topics and difficulty levels, solved across multiple sources (self-authored practice, 
curated problem lists, and competitive programming).

### Graph Algorithms (`basic/graph/`) — the most advanced section
- **Shortest paths:** Dijkstra's algorithm (plain + with min-cost path variant), 
  Bellman-Ford (handles negative weights), shortest path in a DAG via topological sort
- **Minimum Spanning Tree:** Both Kruskal's (via Disjoint Set/Union-Find) and Prim's algorithms
- **Strongly Connected Components:** Kosaraju's algorithm AND Tarjan's algorithm (both implemented)
- **Graph structure analysis:** Articulation points, bridges, cycle detection (directed 
  and undirected, via DFS and topological sort), mother vertex, connected components
- **Traversal-based problems:** BFS/DFS on grids (island counting, rotting oranges, 
  nearest-1 distance, region area), knight's tour on n×n board
- **Representation:** Adjacency list and adjacency matrix implementations from scratch

### Dynamic Programming (`basic/dp/`, `fraz/dp/`, `top_500/dp/`) — the largest section, 90+ problems
- **Classic DP patterns:** 0/1 Knapsack, Unbounded Knapsack, Coin Change (min coins + 
  count combinations), LCS (2-string and 3-string variants), LIS, Edit Distance, 
  Matrix Chain Multiplication
- **String DP:** Palindrome partitioning, longest palindromic subsequence, regular 
  expression matching, wildcard pattern matching, word break (+ word break II), 
  smallest common supersequence
- **Interval/2D DP:** Egg dropping puzzle (+ super egg drop), burst balloons, 
  optimal binary search tree, minimum cost to cut a stick, box stacking
- **Array/Subsequence DP:** Maximum subarray (Kadane's), maximum product subarray, 
  longest increasing/arithmetic subsequence, subset sum, partition problems
- **Combinatorial DP:** Catalan numbers, nCr, counting BSTs, ways to reach a score, 
  ugly numbers / super ugly numbers, bitmasking + DP

### System Design Problems (`fraz/design/`)
- **LRU Cache** and **LFU Cache** — classic cache-eviction design problems
- Design Browser History, Design Underground System (transit tracking), 
  Median from Data Stream, Tweet Counts Per Frequency

### Matrix Problems (`top_500/matrix/`)
- Matrix rotation (90°, in-place variants), spiral/zigzag traversal, flood fill, 
  island counting in 2D grids, boolean matrix problems, shortest path in binary matrix, 
  largest square sub-matrix of 1s (DP-based)

### Binary Search (`binarySearch/easy/`, `fraz/binarySearch/`)
Applied binary search beyond plain lookup — "search on answer" style problems 
(list min replacement, room fitting, robin hood allocation)

### Competitive Programming (`codechef/practice/`)
Problems solved directly from CodeChef practice sets.

### Pattern-Based Practice (`fraz/`)
A second full pass organized by **interview pattern** rather than topic — sliding 
window, two-pointer, backtracking, greedy, hash tables, heaps — reflecting a shift 
toward pattern-recognition-based problem solving (closer to how interview prep is 
typically structured today).

## 📁 Repository Structure

| Folder | Focus |
|---|---|
| `basic/` | Foundational DS&A by topic — arrays, trees, graphs, DP, recursion, sorting, searching, stacks/queues, strings, bit manipulation, math |
| `fraz/` | Second practice pass organized by **interview pattern** (two-pointer, sliding window, backtracking, greedy, design, etc.) |
| `top_500/` | Practice from a curated "Top 500" problem list — arrays, DP, greedy, matrix, backtracking, linked lists, stacks/queues, strings |
| `binarySearch/` | Focused binary search practice (easy tier) |
| `codechef/` | Competitive programming practice from CodeChef |
| `practice/` | General ad-hoc practice (arrays, queues, stacks) |

## 📍 Current Practice — Timeline & Transition

This repository reflects my **earliest, foundational DSA practice** (2022) — solving 
problems in C++ and periodically committing progress here as I worked through topics 
one at a time (commit history shows incremental progress like `sort 1` → `sort 25`, 
`arrays 1` → `arrays 100`).

**I've since moved my active DSA/interview preparation to LeetCode**, where I now 
track problems, patterns, and progress more systematically:

🔗 **[LeetCode Profile — PradeepPeriyasamy](https://leetcode.com/u/PradeepPeriyasamy-1510-nitt/)**

This repo remains public as an accurate record of where that practice started — the 
graph algorithms, DP patterns, and design problems solved here built the foundation 
that my current LeetCode practice builds on.

## Note

This is a practice/learning repo, not a production project. Code reflects iterative, 
topic-by-topic problem-solving practice rather than software engineering best 
practices — no tests, no CI, and minimal structure by design. Some problem 
descriptions/filenames retain informal phrasing from when they were originally 
written.

## License

MIT — see [LICENSE](LICENSE).
