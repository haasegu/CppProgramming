#include "graph.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

void read_edges_from_file(const string &file_name, vector<array<int, 2>> &v)
{
    ifstream fin(file_name);           // Oeffne das File im ASCII-Modus
    if ( fin.is_open() ) {             // File gefunden:
        v.clear();                     // Vektor leeren
        int k,l;
        while ( fin >> k >> l) {v.push_back({k,l});} // Einlesen
        if (!fin.eof()) {
            // Fehlerbehandlung
            cout << " Error handling \n";
            if ( fin.bad() )  {throw runtime_error("Schwerer Fehler in istr");}
            if ( fin.fail() ) { // Versuch des Aufraeumens
                cout << " Failed in reading all data.\n";
                fin.clear();
            }
        }
        v.shrink_to_fit();
    }
    else {                             // File nicht gefunden:
        cout << "\nFile " << file_name << " has not been found.\n\n" ;
        assert( fin.is_open() && "File not found." );       // exeption handling for the poor programmer
    }
    //return;
}


vector<vector<int>> get_node2nodes(vector<array<int,2>> const & edges)
{
    // we assume that the nodes are continuously numbered from 0 to n-1
    //   code works neverthless because n2n[v] remains empty for non-existing node v
    
    // determine number of nodes
    int nnode=-1;
    for (size_t k=0; k<edges.size(); ++k)
    {
        for (size_t j=0; j<edges[k].size(); ++j)
        {
            nnode=max(nnode,edges[k][j]);
        }
    }
    ++nnode;                          // number of nodes

    // Determine the neighborhood for each vertex
    vector<vector<int>> n2n(nnode);
    for (size_t k=0; k<edges.size(); ++k)
    {
        const int v0 = edges[k][0];
        const int v1 = edges[k][1];
        n2n[v0].push_back(v1);         // add v1 to neighborhood of v0
        n2n[v1].push_back(v0);         //     and vice versa
    }
    // ascending sort of entries per node
    for (size_t k=0; k<n2n.size(); ++k)
    {
        sort(n2n[k].begin(),n2n[k].end());
    }

    return n2n;
}


