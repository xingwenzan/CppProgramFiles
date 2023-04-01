cmake_minimum_required(VERSION 3.24)
project(AlgorithmCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgorithmCpp main.cpp BasicAlgorithms/QuickSort/QuickSort.cpp BasicAlgorithms/QuickSort/QuickChange.cpp BasicAlgorithms/MergeSort/MergeSort.cpp BasicAlgorithms/MergeSort/ReversePair.cpp BasicAlgorithms/Dichotomize/RangeOfNumbers.cpp BasicAlgorithms/Dichotomize/CubeRootOfNumber.cpp BasicAlgorithms/HighPrecision/AdditionA.cpp BasicAlgorithms/HighPrecision/AdditionB.cpp BasicAlgorithms/PrefixSumAndDifference/PrefixSum.cpp)
