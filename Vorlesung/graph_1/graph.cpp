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

graph::graph(const string &file_name)
: _edges(0), _nvert(0)
{
    ifstream fin(file_name);           // Oeffne das File im ASCII-Modus
    if ( fin.is_open() ) {             // File gefunden:
//        _edges.clear();                // Vektor leeren
        unsigned int k,l;
        while ( fin >> k >> l) _edges.push_back({k,l}); // Einlesen
        if (!fin.eof()) {
            // Fehlerbehandlung
            cout << " Error handling \n";
            if ( fin.bad() )  throw runtime_error("Schwerer Fehler in istr");
            if ( fin.fail() ) { // Versuch des Aufraeumens
                cout << " Failed in reading all data.\n";
                fin.clear();
            }
        }
        _edges.shrink_to_fit();
    }
    else {                             // File nicht gefunden:
        cout << "\nFile " << file_name << " has not been found.\n\n" ;
        assert( fin.is_open() && "File not found." );       // exeption handling for the poor programmer
    }

    DetermineNumberVertices();

    return;
}


vector<vector<unsigned int>> graph::get_node2nodes() const
{
    size_t nnode=Nvertices();

    // Determine the neighborhood for each vertex
    vector<vector<unsigned int>> n2n(nnode);
    for (size_t k=0; k<_edges.size(); ++k)
    {
        const int v0 = _edges[k][0];
        const int v1 = _edges[k][1];
        n2n.at(v0).push_back(v1);         // add v1 to neighborhood of v0
        n2n.at(v1).push_back(v0);         //     and vice versa
    }
    // ascending sort of entries per node
    for (size_t k=0; k<n2n.size(); ++k)
    {
        sort(n2n[k].begin(),n2n[k].end());
    }


    return n2n;
}

 void graph::DetermineNumberVertices()
 {
     // we assume that the nodes are numbered consecutively from 0 to n-1
    // determine number of nodes
    unsigned int nnode=0;
    for (size_t k=0; k<_edges.size(); ++k)
    {
        for (size_t j=0; j<_edges[k].size(); ++j)
        {
            nnode=max(nnode,_edges[k][j]);
        }
    }
    if (_edges.size()>0) ++nnode;          // more than 1 edge i graph?
    _nvert = nnode;
 }

ostream& operator<<(ostream &s, graph const &rhs)
{
    auto &edges=rhs._edges;
    s << "\n --  Edges  --\n";
    for (size_t k=0; k<edges.size(); ++k)
    {
        s << k << " : ";
        for (size_t j=0; j<edges[k].size(); ++j)
        {
            s << edges[k][j] << " ";
        }
        s << endl;
    }

    s << "Graph with  " << rhs.Nedges() << " edges and  " << rhs.Nvertices() << " vertices" << endl;

    return s;
}

