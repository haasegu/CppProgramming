//graph
#include "graph.h"
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello Graph!" << endl;
    const string name{"g_1_map.txt"};

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
    for (auto const & [key, value]: n2n)
    {
        cout << key << " : ";                  // node number
        for (size_t j=0; j<value.size(); ++j)  //   its neighborhood
        {
            cout << value.at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}
