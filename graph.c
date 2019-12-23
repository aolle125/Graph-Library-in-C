/* NAME : VISHWAJEET VIJAY PARADKAR
   G NO	: G01222771
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
static int depth_first_search(Graph* graph, int v1, int v2);



/*
Malloced and initialized a new Graph structure,
and returned a pointer to it.
*/
Graph* graph_initialize() {
	Graph* new = malloc(sizeof(Graph));
	if (new == NULL) {		//Return NULL on any error
		return NULL;
	}
	int i, j;
	new->max_vertex = 0;
	/* Looping through all of the indexes
	to initialize them*/
	for (i = 0; i < MAX_VERTICES; i++) {
		new->visited[i] = 0;		//Initializing visited array
		for (j = 0; j < MAX_VERTICES; j++) {
			new->adj_matrix[i][j] = -1;		//Initializing adjacency matrix
		}
	}
	return new;		//Returning the pointer to the graph structure
}

/* This function adds vertex number v1 to the graph */
int graph_add_vertex(Graph* graph, int v1) {
	if (graph == NULL) {			//Return -1 on any error
		return -1;
	}
	else if (v1 < 0 || v1 >= MAX_VERTICES) {		//If v1 is not a legal vertex (ie. < 0 or >= MAX_VERTICES), return error
		return -1;
	}
	else if (graph->adj_matrix[v1][v1] == -1) {		//Adding vertex v1 to the graph
		graph->adj_matrix[v1][v1] = 0;
		return 0;
	}
}


/* This function should check if the graph
	has vertex number v1 in the graph */
int graph_contains_vertex(Graph* graph, int v1) {
	if (graph == NULL) {			//Return NULL on any error
		return 0;
	}

	if (v1 < 0 || v1 >= MAX_VERTICES) {		//If v1 is not a legal vertex (ie. < 0 or >= MAX_VERTICES), return error
		return 0;
	}
	if (graph->adj_matrix[v1][v1] > -1) {		//Return 1 if the vertex exists
		return 1;
	}
	else {
		return 0;
	}
}


/* This function should remove vertex number v1 from the graph.
If there are any edges connected to this vertex, they should also be removed */
int graph_remove_vertex(Graph* graph, int v1) {
	int i;
	if (graph == NULL) {			//Return -1 on any error
		return -1;
	}
	else if (!graph_contains_vertex) {		//If v1 is not in the graph, return 0
		return 0;
	}
	else {
		//Removing all outgoing edges
		for (i = 0; i < MAX_VERTICES; i++) {
			graph->adj_matrix[v1][i] = -1;

			//Removing all incoming edges
			if (graph_contains_edge(graph, i, v1)) {
				graph_remove_edge(graph, i, v1);
			}
		}
		return 0;
	}
	return -1;
}


/* This function adds an edge
	from v1 to v2 with weight of wt */
int graph_add_edge(Graph* graph, int v1, int v2, int wt) {
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}

	//If v1 and v2 are not in the graph, return -1
	else if (!graph_contains_vertex(graph, v1) && !graph_contains_vertex(graph, v2)) {
		return -1;
	}
	else {
		//Adding the edge in the graph and returning success
		graph->adj_matrix[v1][v2] = wt;
		return 0;
	}
}

/* This function checks if
	an edge from v1 to v2 exists. */
int graph_contains_edge(Graph* graph, int v1, int v2) {
	if (graph == NULL) {		//Return 0 on any error
		return 0;
	}

	//If v1 and v2 are not in the graph, return -1
	else if (!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return 0;
	}

	//Checking if edge exists and returning 1
	else if (graph->adj_matrix[v1][v2] > 0) {
		return 1;
	}
	else {
		return 0;
	}
}


/* This function remove s
	an edge from v1 to v2 */
int graph_remove_edge(Graph* graph, int v1, int v2) {
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}

	//If v1 and v2 are not in the graph, return -1
	else if (!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return -1;
	}

	//If v1 and v2 exist, but have no edges already, it’s a success

	else if (v1 == v2) {
		//Example position [0][0] should have value 0 as it indicates presence of vertex
		graph->adj_matrix[v1][v2] = 0;
		return 0;
	}
	else {
		graph->adj_matrix[v1][v2] = -1;
		return 0;
	}
}


/* This function returns the number
	of vertices in the graph. */
int graph_num_vertices(Graph* graph) {
	int i, count = 0;
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}

	//Iterating and adding the number of vertices in the graph
	for (i = 0; i < MAX_VERTICES; i++) {
		if (graph->adj_matrix[i][i] > -1) {
			count++;
		}
	}
	return count;		//Returning the number of vertices
}

/* This function returns the number
	of edges in the graph. */
int graph_num_edges(Graph* graph) {
	int i, j, count = 0;
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}
	//Iterating and adding the number of edges in the graph
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (graph_contains_edge(graph, i, j)) {
				count++;
			}
		}
	}
	return count;		//Returning the number of edges
}

/* This function returns the sum of
	all edge weights in the graph */

int graph_total_weight(Graph* graph) {
	int i, j, count = 0;
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}
	//Iterating and adding the weight of edges in the graph
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (graph->adj_matrix[i][j] > -1) {
				count = count + graph->adj_matrix[i][j];
			}
		}
	}
	return count;		//Returning the total weight
}

/* This function returns the total degree of edges on Vertex V1
 including both the in-degree and out-degree combined */

int graph_get_degree(Graph* graph, int v1) {
	int i, count = 0;
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}

	//If v1 is not in the graph, return -1
	if (!graph_contains_vertex(graph, v1)) {
		return -1;
	}

	for (i = 0; i < MAX_VERTICES; i++) {
		//Checking outgoing vertices
		if (graph_contains_edge(graph, v1, i)) {
			count++;
		}
		//Checking incoming vertices
		if (graph_contains_edge(graph, i, v1)) {
			count++;
		}

	}
	return count;	//Returning the total degree

}


int graph_get_edge_weight(Graph* graph, int v1, int v2) {
	if (graph == NULL) {			//Return -1 on any error
		return -1;
	}
	//If v1 and v2 are not in the graph, return -1
	else if (!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return -1;
	}
	//If edge exists, return the edge weight
	else if (graph_contains_edge(graph, v1, v2)) {
		return graph->adj_matrix[v1][v2];
	}
	else {
		return -1;
	}
}

/* Return 1 if there is an edge from v1->v2 or an edge from v2->v1 */
int graph_is_neighbor(Graph* graph, int v1, int v2) {
	if (graph == NULL) {		//Return 0 on any error
		return 0;
	}
	//If v1 and v2 are not in the graph, return 0
	else if (!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return 0;
	}
	//If edge exists, return 1
	else if (graph_contains_edge(graph, v2, v1) || graph_contains_edge(graph, v1, v2)) {
		return 1;
	}
	else {
		return 0;
	}
}

/* This function returns all Predecessors of Vertex V1
	as a dynamically allocated array. */
int* graph_get_predecessors(Graph* graph, int v1) {
	int* arr = malloc(sizeof(int) * MAX_VERTICES);		//Malloced dynamic array
	int i, count = 0, v = 0;
	if (graph == NULL) {		//Return NULL on any error
		return NULL;
	}
	//If v1 is not in the graph, return NULL
	if (!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	for (i = 0; i < MAX_VERTICES; i++) {
		if (graph_contains_edge(graph, i, v1)) {
			arr[v] = i;		//Appending a predecessor to the dynamically allocated array
			v++;			//Adding count of array by 1
		}
	}

	//The last entry of this array needs to be -1
	arr[v] = -1;
	return arr;		//Returning the array
}

/* This function returns all successors of Vertex V1
	as a dynamically allocated array. */
int* graph_get_successors(Graph* graph, int v1) {
	int* arr = malloc(sizeof(int) * MAX_VERTICES);		//Malloced dynamic array
	int i, count = 0, v = 0;
	if (graph == NULL) {		//Return NULL on any error
		return NULL;
	}
	//If v1 is not in the graph, return NULL
	if (!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	for (i = 0; i < MAX_VERTICES; i++) {
		if (graph_contains_edge(graph, v1, i)) {
			arr[v] = i;			//Appending a successor to the dynamically allocated array
			v++;
		}
	}
	//The last entry of this array needs to be -1
	arr[v] = -1;
	return arr;		//Returning the array
}

//This function checks if there is path from v1 to v2.
int graph_has_path(Graph* graph, int v1, int v2) {
	int flag = 0;
	if (graph == NULL) {		//Return 0 on any error
		return 0;
	}
	//If v1 and v2 are not in the graph, return 0
	if (!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return 0;
	}

	//If v1 and v2 are same and their value is 0, no self loop present
	if ((graph_get_edge_weight(graph, v1, v2) == 0) && v1 == v2) {
		return 0;
	}
	//Calling the depth first search function
	flag = depth_first_search(graph, v1, v2);
	return flag;		//Returning the output
}

//Local Depth First Search Function
static int depth_first_search(Graph* graph, int v1, int v2) {
	int flag1 = 0;
	if (graph->visited[v1] == 1) {
		return flag1;		//Returning 0, which would eventually be the value of flag1 at this point
	}
	int i, j;
	int* arr = NULL;
	graph->visited[v1] = 1;		//Setting visited of that position in visited array as 1
	if (v1 == v2) {
		flag1 = 1;
		return flag1;		//Set flag1 = 1 and return success
	}
	//Getting the successors of the array
	arr = graph_get_successors(graph, v1);
	for (i = 0; arr[i] != -1; i++) {
		/* Check If that position is visited and the path has
		not yet been found */
		if (graph->visited[arr[i]] != 1 && flag1 != 1) {
			flag1 = depth_first_search(graph, arr[i], v2);		//RECURSION
		}
	}
	return flag1;
}

//Graphical representation of your adj matrix
void graph_print(Graph* graph) {
	if (graph == NULL) {		//Return on any error
		return;
	}
	int arr[20], v = 0, i = 0, j = 0;
	printf("\nAdjacency matrix\n");
	printf("    ");
	for (i = 0; i < MAX_VERTICES; i++) {
		if (graph_contains_vertex(graph, i)) {
			arr[v] = i;
			v++;
		}
	}
	for (i = 0; i < v; i++) {
		printf("%3d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < v; i++) {
		printf("-----");
	}
	printf("\n");
	for (i = 0; i < v; i++) {
		printf("%3d| ", arr[i]);
		for (j = 0; j < v; j++) {
			printf("%3d ", graph->adj_matrix[arr[i]][arr[j]]);
		}
		printf("\n");
	}
	return;
}

/* This function will load a graph from a file.
If you want to store a vertex with no edges, put the vertex number on its own line.
If you have an edge to store, put it in this comma separated format, on its own line:
vertex1, vertex2, edge_weight */
int graph_load_file(Graph* graph, char* filename) {
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {		//Return -1 on any error
		return -1;
	}
	char* token;
	char line[FILE_ENTRY_MAX_LEN];
	int digit = 0;
	int r = 0;

	//Reading the lines from the file one by one
	while (fgets(line, sizeof(line), fp) != NULL) {
		int number_count = 1;
		/* A sequence of calls to strtok split str into tokens,
		which are sequences of contiguous characters separated
		by any of the characters that are part of delimiters. */
		token = strtok(line, ", ");
		int first_digit = strtol(token, NULL, 10); //strtol converts number to long, then typecasted to int with base 10

		//Check if the vertex exists, else add it
		if (graph_contains_vertex(graph, first_digit) != 1)
		{
			r = graph_add_vertex(graph, first_digit);
		}
		number_count++;
		while (token != NULL)
		{
			/* The function expects a null pointer and uses the position right
			after the end of the last token as the new starting location for scanning */

			token = strtok(NULL, ", ");
			if (token != NULL)
			{
				if (number_count == 2)
				{
					digit = strtol(token, NULL, 10);
					//If present in the file, add vertex v2
					if (graph_contains_vertex(graph, digit) != 1)
					{
						r = graph_add_vertex(graph, digit);
					}
					number_count++;
				}
				else
				{	//Adding the weight of the edge
					int weight = strtol(token, NULL, 10);
					r = graph_add_edge(graph, first_digit, digit, weight);
				}
			}
		}
		printf("\n");
	}
	fclose(fp);		//Closing the file
	return 0;
}



//This function will save your graph to a file
int graph_save_file(Graph* graph, char* filename) {
	if (graph == NULL) {		//Return -1 on any error
		return -1;
	}
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {		//Return -1 on any error
		return -1;
	}
	int i, j, wt = 0, count;
	for (i = 0; i < MAX_VERTICES; i++) {
		count = 0;
		//Check to see if vertex exists and print it to the file
		if (graph_contains_vertex(graph, i)) {
			for (j = 0; j < MAX_VERTICES; j++) {
				//If edge exists, print and save to file
				if (graph_contains_edge(graph, i, j)) {
					wt = graph_get_edge_weight(graph, i, j);
					count++;		//Incrementing count
					fprintf(fp, "%d,%d,%d\n", i, j, wt);		//Printing v1,v2,weight
				}
			}
			//If count is 0, no edge exists, so only print the vertex
			if (count == 0) {
				fprintf(fp, "%d\n", i);
			}
		}
	}
	fclose(fp);		//Closing the file
	return 0;
}


//This function outputs your graph in a format for the GraphViz program as a file
void graph_output_dot(Graph* graph, char* filename) {
	if (graph == NULL) {		//Return on any error
		return;
	}
	FILE* fp1 = fopen(filename, "w");
	if (fp1 == NULL) {		//Return on any error
		return;
	}
	int i, j, wt;
	//Printing in the dot file format
	fprintf(fp1, "digraph %s\n", "{");
	for (i = 0; i < MAX_VERTICES; i++) {
		//Check to see if vertex exists and print it to the file
		if (graph_contains_vertex(graph, i)) {
			fprintf(fp1, "%d;\n", i);
			for (j = 0; j < MAX_VERTICES; j++) {
				//Print every outgoing edge of vertex i->j
				if (graph_contains_edge(graph, i, j)) {
					wt = graph_get_edge_weight(graph, i, j);
					fprintf(fp1, "%d -> %d [label = %d];\n", i, j, wt);
				}
			}
		}
	}
	fprintf(fp1, "%s\n", "}");
	fclose(fp1);		//Closing the file
}
