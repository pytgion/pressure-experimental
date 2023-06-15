#ifndef MATTER_HPP
#define MATTER_HPP

#include <iostream>
#include <string>

class LiquidContainer {
private:
    double height;       // Height of the liquid
    double density;      // Density of the liquid
    double pressure;     // Pressure of the liquid

public:
    LiquidContainer()
        : height(0.0), density(0.0) {}

    void setHeight(double h) {
        height = h;
    }

    void setDensity(double d) {
        density = d;
    }

    double calculatePressure() {
        pressure = density * 9.81 * height;  // Pressure calculation: P = density * g * h
        return pressure;
    }
};

class GasContainer {
private:
    double volume;       // Volume of the gas
    double temperature;  // Temperature of the gas
    double pressure;     // Pressure of the gas

public:
    GasContainer()
        : volume(0.0), temperature(0.0) {}

    void setVolume(double v) {
        volume = v;
    }

    void setTemperature(double t) {
        temperature = t;
    }

    double calculatePressure() {
        pressure = (temperature * 8.314) / volume;  // Pressure calculation: P = (nRT) / V
        return pressure;
    }
};

class PressureMeasurement {
private:
    double fluidDensity;     
    double fluidHeight;      
    double objectDepth;      
    double gravity;         //9.8 m/s^2

public:
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
};

#endif