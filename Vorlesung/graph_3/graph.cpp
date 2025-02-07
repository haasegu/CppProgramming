#include "graph.h"
#include <algorithm>
#include <cassert>
#include <fstream>
using namespace std;

[[maybe_unused]] graph::graph(const string &file_name)
    : _edges(0), _vertices(), _maxvert(-1)             // graph_2
{
    ifstream fin(file_name);           // Oeffne das File im ASCII-Modus
    if ( fin.is_open() ) {             // File gefunden:
//        _edges.clear();                // Vektor leeren
        unsigned int k, l;
        while ( fin >> k >> l) {_edges.push_back({k, l});} // Einlesen
        if (!fin.eof()) {
            // Fehlerbehandlung
            cout << " Error handling \n";
            if ( fin.bad() )  {throw runtime_error("Schwerer Fehler in istr");}
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
}


vector<vector<unsigned int>> graph::get_node2nodes() const
{
//    size_t nnode=Nvertices();
    size_t nnode = Max_vertex() + 1;      // graph_2

    // Determine the neighborhood for each vertex
    vector<vector<unsigned int>> n2n(nnode);
    for (auto _edge : _edges) {
        auto const v0 = _edge[0];
        auto const v1 = _edge[1];
        n2n.at(v0).push_back(v1);         // add v1 to neighborhood of v0
        n2n.at(v1).push_back(v0);         //     and vice versa
    }
    // ascending sort of entries per node
    for (auto & k : n2n) {
        sort(k.begin(), k.end());
    }


    return n2n;
}
// graph_2
void graph::DetermineNumberVertices()
{
    // we assume that the nodes are numbered consecutively from 0 to n-1
    // determine number of nodes
    _vertices.clear();
    unsigned int nnode = 0;
    for (auto & _edge : _edges) {
        for (unsigned int & j : _edge) {
            nnode = max(nnode, j);
            _vertices.insert(j);       // graph_2
        }
    }
    if ( !_edges.empty() )    // at least one edge in graph?
       {_maxvert = nnode;}
    else
       {_maxvert=-1;}
}

ostream &operator<<(ostream &s, graph const &rhs)
{
    s << "Graph with  " << rhs.Nedges() << " edges and  " << rhs.Nvertices() << " vertices" << endl;

    const auto &edges = rhs._edges;
    s << "\n --  Edges  --\n";
    for (size_t k = 0; k < edges.size(); ++k) {
        s << k << " : ";
        for (unsigned int j : edges[k]) {
            s << j << " ";
        }
        s << endl;
    }

    s << "\n --  Vertices  --\n";               // graph_2
    for (auto v : rhs._vertices) {              // graph_2
        s << v << "  ";
    }
    s << endl;

    return s;
}


[[maybe_unused]] bool graph::Append(unsigned int v1, unsigned int v2)   // graph_3
{
    const auto ip = find(_edges.cbegin(), _edges.cend(), Edge{v1, v2});
    bool edgeFound(ip == _edges.cend());     // really a new edge
    if (edgeFound) {
        _edges.push_back(Edge{v1, v2});
        _vertices.insert(v1);
        _maxvert = max(_maxvert, v1);
        _vertices.insert(v2);
        _maxvert = max(_maxvert, v2);
    }
    return edgeFound;
}

bool graph::Delete(Edge const& e)                      // graph_3
{
    const auto ip = find(_edges.cbegin(), _edges.cend(), e);
    bool edgeFound(ip != _edges.cend());     //  edge found
    if (edgeFound) {
        _edges.erase(ip);
        DetermineNumberVertices(); // updates _vertices, _maxvert
    }
    return edgeFound;
}

[[maybe_unused]] bool graph::Delete(unsigned int v1, unsigned int v2)   // graph_3
{
    return Delete(Edge{v1, v2});
}

void graph::Delete(vector<Edge> const &v)              // graph_3
{
    for (const auto &e : v) {
        const auto ip = find(_edges.cbegin(), _edges.cend(), e);
        bool edgeFound(ip != _edges.cend());     //  edge found
        if (edgeFound) {
            _edges.erase(ip);
        }
    }
    DetermineNumberVertices(); // updates _vertices, _maxvert: called only once
}

