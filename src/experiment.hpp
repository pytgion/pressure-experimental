#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include <iostream>
#include <vector>
#include "material.hpp"
#include "material.hpp"
#include <thread>
#include <mutex>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


typedef struct experimentContainerHub {
    size_t index;
    double x;
    double y;
    double z;
    struct experimentContainerHub  *next;
} exHub;

class Experiment {
private:
	double liquidDensity = 1000.0;
    static int count;
    std::mutex mutex;
    std::vector<double> weight;
    std::vector<double> surface;
    std::vector<double> height;

public:
    Experiment();
    ~Experiment();
    int addValue(double w, double s);
    int getCount();
    void printValues();
    void calculateHeight();
};

int Experiment::count = 0;

Experiment::Experiment() {
    // Constructor implementation
}

Experiment::~Experiment() {
    // Destructor implementation
}

int Experiment::addValue(double w, double s) {
    weight.push_back(w);
    surface.push_back(s);
    return ++count;
}

int Experiment::getCount() {
    return count;
}

void Experiment::printValues() {
    for (int i = 0; i < count; i++) {
        std::cout << (i + 1) << ". object:" << "\n";
        std::cout << "Weight: " << weight[i] << std::endl;
        std::cout << "Surface: " << surface[i] << std::endl;
        std::cout << std::endl;
    }
}

void Experiment::calculateHeight() {
    height.resize(count);

    std::vector<std::thread> threads;
    for (int i = 0; i < count; i++) {
        threads.emplace_back([this, i]() {
            double w = weight[i];
            double s = surface[i];
            double h = (liquidDensity * w) / s;

            std::lock_guard<std::mutex> lock(mutex);
            height[i] = h;
            std::cout << RED << "Height of i = " << height[i] << "." << RESET << std::endl;
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

#endif
