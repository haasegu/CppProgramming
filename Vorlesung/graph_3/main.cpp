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
    graph g1{"g_2.txt"};

    cout << g1 << endl;

    // construct mapping nodes to nodes
    auto n2n=g1.get_node2nodes();

    cout << "\n --  Nodes to Node  --\n";
    for (size_t k=0; k<n2n.size(); ++k)
    {
        cout << k << " : ";
        for (unsigned int j : n2n[k])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
    // ---------------
    vector<std::array<unsigned int,2>> ve{ {1,2}, {5,4}, {2,5} };
    g1.Delete(ve);
    cout << g1 << endl;

    return 0;
}
