- (0, 4) weight 1
- (4, 3) weight -5
- (2, 3) weight -2
- (3, 1) weight 1
- (2, 1) weight 7
- (0, 1) weight 4

### Step 1: Add a New Vertex and Initialize Weights
We add a new vertex \(s\) and connect it to all other vertices with edges of weight 0. The new edges are:

- (s, 0) weight 0
- (s, 1) weight 0
- (s, 2) weight 0
- (s, 3) weight 0
- (s, 4) weight 0

### Step 2: Apply Bellman-Ford Algorithm
Run Bellman-Ford from the new vertex \(s\) to find the shortest path distances \(h(v)\) from \(s\) to every other vertex \(v\).

1. Initialize \(h(s) = 0\) and \(h(v) = \infty\) for all other vertices \(v\).
2. Relax all edges \(V-1\) times (where \(V\) is the number of vertices including \(s\)).

Initial distances:
- \(h(s) = 0\)
- \(h(0) = \infty\)
- \(h(1) = \infty\)
- \(h(2) = \infty\)
- \(h(3) = \infty\)
- \(h(4) = \infty\)

**First iteration of edge relaxation:**
- \(h(0) = 0\) (via (s, 0))
- \(h(1) = 0\) (via (s, 1))
- \(h(2) = 0\) (via (s, 2))
- \(h(3) = 0\) (via (s, 3))
- \(h(4) = 0\) (via (s, 4))
- \(h(3) = -5\) (via (4, 3) since \(h(4) + (-5) < h(3)\))

**Second iteration of edge relaxation:**
- \(h(3) = -5\) (no change)
- \(h(1) = -4\) (via (3, 1) since \(h(3) + 1 < h(1)\))

**Third, Fourth, and Fifth iterations:**
- No further changes as all shortest paths are already relaxed.

Final distances:
- \(h(s) = 0\)
- \(h(0) = 0\)
- \(h(1) = -4\)
- \(h(2) = 0\)
- \(h(3) = -5\)
- \(h(4) = 0\)

### Step 3: Reweight the Original Graph
Using \(h\) values, compute the new weights \(w'(u, v) = w(u, v) + h(u) - h(v)\):

1. \(w'(0, 4) = 1 + 0 - 0 = 1\)
2. \(w'(4, 3) = -5 + 0 - (-5) = 0\)
3. \(w'(2, 3) = -2 + 0 - (-5) = 3\)
4. \(w'(3, 1) = 1 + (-5) - (-4) = 0\)
5. \(w'(2, 1) = 7 + 0 - (-4) = 11\)
6. \(w'(0, 1) = 4 + 0 - (-4) = 8\)

### Step 4: Apply Dijkstra’s Algorithm
Run Dijkstra's algorithm from each vertex on the reweighted graph to find the shortest paths:

**From vertex 0:**
- (0, 4) -> Distance to 4 is 1
- (0, 1) -> Distance to 1 is 8
- (4, 3) -> Distance to 3 is 1 + 0 = 1
- (3, 1) -> Distance to 1 is 1 + 0 = 1

So, from 0:
- 0 to 4: 1
- 0 to 1: 1
- 0 to 3: 1

**From vertex 1:**
- No outgoing edges from 1 in the reweighted graph.

**From vertex 2:**
- (2, 3) -> Distance to 3 is 3
- (3, 1) -> Distance to 1 is 3 + 0 = 3

So, from 2:
- 2 to 3: 3
- 2 to 1: 3

**From vertex 3:**
- (3, 1) -> Distance to 1 is 0

**From vertex 4:**
- (4, 3) -> Distance to 3 is 0
- (3, 1) -> Distance to 1 is 0 + 0 = 0

So, from 4:
- 4 to 3: 0
- 4 to 1: 0
