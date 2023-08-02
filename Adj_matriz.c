#include<stdio.h>
#include<stdlib.h>

int** CreateGraph(int num_vertex)
{
    int **graph = (int**)malloc(num_vertex * sizeof(int*));

    for(int i = 0; i < num_vertex; i++)
    {
        graph[i] = (int*)malloc(num_vertex * sizeof(int));

        for(int j = 0; j < num_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    return graph;
}

void AddEdge(int **graph,int origin, int destiny)
{
    // if the graph is directed
    graph[origin][destiny] = 1;

    // if the graph is undirected uncomment the line below
    //graph[destiny][origin] = 1;

}

void PrintGraph(int **graph, int num_vertex)
{
    printf("\nRepresentation of the graph in the form of a matrix.\n\n");

    for(int g = 0; g < num_vertex; g++)
    {
        printf("\033[4m  %2d\033[0m",g);
    }
    printf("\n");

    for(int i = 0; i < num_vertex; i++)
    {
        printf("%d|",i);
    
        for (int j = 0; j < num_vertex; j++)
        {
            printf("%2d  ",graph[i][j]);
        }
        printf("\n");  
    }
    printf("\n");
}

int main()
{
    int **graph = CreateGraph(6);

    AddEdge(graph,0,1);
    AddEdge(graph,1,2);
    AddEdge(graph,2,3);
    AddEdge(graph,3,0);
    AddEdge(graph,4,3);
    AddEdge(graph,4,5);
    AddEdge(graph,5,0);

    PrintGraph(graph,6);
}