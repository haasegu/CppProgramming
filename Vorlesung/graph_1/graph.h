#pragma once

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
  A simple graph class that requires a consecutive numbering of the vertices starting from 0.
*/
class graph {
public:
    /** \brief Reads edges for graph from file.
     *
     *  If the file  @p file_name does not exist then the code stops with an appropriate message.
     *
     *  A consecutive numbering of the vertices is required.
     *
     * @param[in]    file_name   name of the ASCII-file
     */
    graph(const std::string &file_name);

    graph(graph const & org) = default;
    graph& operator=(graph const & rhs) = default;

    /**
      Determines the neighboring vertices for each node from the edge definition.
      The node itself is not contained in the neighboring vertices.

      @return       vector[nn][*] with all neighboring vertices for each node
    */
    std::vector<std::vector<unsigned int>> get_node2nodes() const;

    /**
      @return       number of edges
    */
    size_t Nedges() const
    {
        return _edges.size();
    }

    /**
      @return       number of vertices
    */
    size_t Nvertices() const
    {
        return _nvert;
    }

    friend std::ostream& operator<<(std::ostream &s, graph const &rhs);

private:
    /**
      Determines the number of vertices from the edge information.
      It requires a consecutive numbering of the vertices starting from 0.
    */
    void DetermineNumberVertices();

    std::vector<std::array<unsigned int, 2>> _edges;  /**< stores the two vertices for each edge */
    size_t                                   _nvert;  /**< number of vertices */

};

