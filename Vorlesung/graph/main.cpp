//graph
#include "graph.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello Graph!" << endl;
    const string name{"g_1.txt"};

    // read the edges
    vector<array<int,2>> edges;
    read_edges_from_file(name, edges);

    cout << "\n --  Edges  --\n";
    for (size_t k=0; k<edges.size(); ++k)
    {
        cout << k << " : ";
        for (size_t j=0; j<edges[k].size(); ++j)
        {
            cout << edges[k][j] << " ";
        }
        cout << endl;
    }

    // construct mapping nodes to nodes
    auto n2n=get_node2nodes(edges);

    cout << "\n --  Nodes to Node  --\n";
    for (size_t k=0; k<n2n.size(); ++k)
    {
        cout << k << " : ";                    // node number
        for (size_t j=0; j<n2n[k].size(); ++j) //   its neighborhood
        {
            cout << n2n[k].at(j) << " ";
        }
        cout << endl;
    }


    return 0;
}
