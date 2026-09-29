#include <iostream>
#include <mpi.h>
#include <numeric>
#include <vector>

double mean(const std::vector<double>& values) {
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

int main(int argc, char** argv) {

    for(int i = 0; i < argc; i++)
        std::cout << "argv[" << i << "]=" << argv[i] << '\n';
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const std::vector<double> temperatures{18.0, 20.0, 22.0, 26.0};
    std::cout << "[out] rank=" << rank << " mean=" << mean(temperatures) << '\n';
    std::cerr << "[err] rank=" << rank << " mean=" << mean(temperatures) << '\n';
    MPI_Finalize();
}