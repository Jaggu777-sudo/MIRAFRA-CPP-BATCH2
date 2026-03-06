#include <iostream>
#include <vector>
#include <iomanip> // Required for manipulators of cin and cout, std::setw(),  std::setprecision(3)
#include <limits>//std::numeric_limits

template<typename T>
class DirectedWeightedGraph {
private:
    int V;
    T INF; // infinity -INF no edge
    std::vector<std::vector<T>> adjMatrix;

public:

    DirectedWeightedGraph(int vertices)
        : V(vertices),
          INF(std::numeric_limits<T>::max()), //returns the largest finite value of the given type
          adjMatrix(vertices, std::vector<T>(vertices, INF)) {} // constructor initialialized no edge = INF

    void addEdge(int src, int dest, T weight) {
        if (src >= 0 && src < V && dest >= 0 && dest < V) {
            adjMatrix[src][dest] = weight;  // Directed edge
        }
    }

    void display() const {
        std::cout << "\nAdjacency Matrix:\n";

        for (const auto& row : adjMatrix) // // Range-based loop - row selection
        {         
            for (const auto& value : row) {          // Range-based loop each value in a ROW
                if (value == INF)
                    std::cout << std::setw(6) << "~";
                else
                    std::cout << std::fixed<< std::setw(6)<<std::setprecision(1) << value;
            }
            std::cout << "\n";
        }
    }
};

int main() {

    DirectedWeightedGraph<float> graph(4);

    graph.addEdge(0, 1, 2.5);
    graph.addEdge(0, 2, 2.8);
    graph.addEdge(1, 3, 3.7);
    graph.addEdge(2, 1, 1.7);
    graph.addEdge(2, 3, 6.8);

    graph.display();

    return 0;
}

