#include <iostream>
using namespace std;
#define INFINITY 999
#define MAX 5

void dijktra(int G[MAX][MAX], int n, int startnode);

int main()
{
    int G[MAX][MAX] = {
        {0, 1, 0, 3, 10},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 2, 1},
        {3, 0, 2, 0, 6},
        {10, 0, 1, 6, 0}};
    int n = 5, u = 0;
    clock_t start, end;
    start = clock();
    dijktra(G,n,u);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << time_taken;
    return 0;
}
void dijktra(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindis, nextnode, i ,j;

    for(i=0; i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }
    for ( i = 0; i < n; i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count = 1;
    
    while(count<n-1)
    {
        mindis=INFINITY;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindis && visited[i])
            {
                mindis=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindis+cost[nextnode][i]<distance[i])
                {
                    distance[i] = mindis + cost[nextnode][i];
                    pred[i]=nextnode;
                
                }
            }
        }
        count++;
    }
    // for(i=0;i<n;i++)
    // {
    //     if(i!=startnode)
    //     {
    //         count<<"\nDistance of node "<<i<<" = "<<distance[i];
    //         cout<<"\npath "<<i;
    //         j=i;
    //     }
    //     do{
    //         j=pred[i];
    //         cout<<" <- "<<j;
    //     }while (j!=startnode);
        
    // }
}
