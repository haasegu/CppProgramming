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
    const graph g1{"g_1.txt"};

    cout << g1 << endl;

    // construct mapping nodes to nodes
    auto n2n=g1.get_node2nodes();

    cout << "\n --  Nodes to Node  --\n";
    for (size_t k=0; k<n2n.size(); ++k)
    {
        cout << k << " : ";
        for (size_t j=0; j<n2n[k].size(); ++j)
        {
            cout << n2n[k].at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}
