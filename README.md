Project Details-

In this project, I will create a new file called graph.c, in which I will implement each of the
functions that are described in graph.h.

Sample Graph:
Metrics:
Num Vertices: 7
Num Edges: 8
Total Weight of Graph: 25
There is a Path from 4 to 5
There is no Path from 4 to 6
Degree of Vertex 3: 5
Successors of Vertex 3: [0 3 5 -1]
Predecessors of Vertex 3: [1 3 -1]
Is 2 a Neighbor of 0? Yes
Edge Weight of 3 -> 2 is
The graph at the right was loaded from the
following file using graph_load_file function:
0
0,1,1
0,2,1
0,4,3
1
1,3,1
2
3,0,5
3,3,9
3,5,2
4,0,3
456
This also makes the following dot file (yours may differ, but it should generate the same image):
digraph {
0;
0 -> 1 [label = 1];
0 -> 2 [label = 1];
0 -> 4 [label = 3];
1;
1 -> 3 [label = 1];
2;
3 -> 0 [label = 5];
3 -> 3 [label = 9];
3 -> 5 [label = 2];
4 -> 0 [label = 3];
4;
5;
6;
}
0
1
1
2
1
4
3
3
1
3
5
9
2
