#include "matter.hpp"

double liquidPressureExperiment(double height, double density) {
    LiquidContainer liquidContainer;
    liquidContainer.setHeight(height);
    liquidContainer.setDensity(density);
    double liquidPressure = liquidContainer.calculatePressure();
    return liquidPressure;
}

double gasPressureExperiment(double volume, double temperature) {
    GasContainer gasContainer;
    gasContainer.setVolume(volume);
    gasContainer.setTemperature(temperature);
    double gasPressure = gasContainer.calculatePressure();
    return gasPressure;
}

double pressureMeasurementExperiment(double fluidDensity, double fluidHeight, double objectDepth, double gravity) {
    PressureMeasurement pressureMeasurement;
    pressureMeasurement.setFluidDensity(fluidDensity);
    pressureMeasurement.setFluidHeight(fluidHeight);
    pressureMeasurement.setObjectDepth(objectDepth);
    pressureMeasurement.setGravity(gravity);
    double measuredPressure = pressureMeasurement.calculatePressure();
    return measuredPressure;
}
