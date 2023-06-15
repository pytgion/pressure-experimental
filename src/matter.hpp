#ifndef MATTER_HPP
#define MATTER_HPP

#include <iostream>
#include <string>

class LiquidContainer {
private:
    double height;
    double density;
    double pressure;

public:
    LiquidContainer(double h = 15.0, double d = 1000.0)
        : height(h), density(d) {}

    void setHeight(double h = 15.0) {
        height = h;
    }

    void setDensity(double d = 1000.0) {
        density = d;
    }

    double calculatePressure() {
        pressure = density * 9.81 * height;
        return pressure;
    }
};

class GasContainer {
private:
    double volume;
    double temperature;
    double pressure;

public:
    GasContainer(double v = 25.0, double t = 25.0)
        : volume(v), temperature(t) {}

    void setVolume(double v) {
        volume = v;
    }

    void setTemperature(double t) {
        temperature = t;
    }

    double calculatePressure() {
        pressure = (temperature * 8.314) / volume;
        return pressure;
    }
};

class PressureMeasurement {
private:
    double fluidDensity;
    double fluidHeight;
    double objectDepth;
    double gravity;

public:
    PressureMeasurement(double density = 0.0, double height = 0.0, double depth = 0.0, double g = 0.0)
        : fluidDensity(density), fluidHeight(height), objectDepth(depth), gravity(g) {}

    void setFluidDensity(double density) {
        fluidDensity = density;
    }

    void setFluidHeight(double height) {
        fluidHeight = height;
    }

    void setObjectDepth(double depth) {
        objectDepth = depth;
    }

    void setGravity(double g) {
        gravity = g;
    }

    double calculatePressure() {
        double fluidPressure = fluidDensity * gravity * (fluidHeight - objectDepth);
        return fluidPressure;
    }

    double liquidPressureExperiment(double height, double density) {
        LiquidContainer liquidContainer(height, density);
        double liquidPressure = liquidContainer.calculatePressure();
        return liquidPressure;
    }

    double gasPressureExperiment(double volume, double temperature) {
        GasContainer gasContainer(volume, temperature);
        double gasPressure = gasContainer.calculatePressure();
        return gasPressure;
    }

    double pressureMeasurementExperiment(double fluidDensity, double fluidHeight, double objectDepth, double gravity) {
        PressureMeasurement pressureMeasurement(fluidDensity, fluidHeight, objectDepth, gravity);
        double measuredPressure = pressureMeasurement.calculatePressure();
        return measuredPressure;
    }

};

#endif
