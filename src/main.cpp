#include "matter.hpp"
#include "material.hpp"

int main() {
    // LiquidContainer liquidContainer;
    // double liquidHeight, liquidDensity;
    // std::cout << "Enter the height of the liquid: ";
    // std::cin >> liquidHeight;
    // std::cout << "Enter the density of the liquid: ";
    // std::cin >> liquidDensity;
    // liquidContainer.setHeight(liquidHeight);
    // liquidContainer.setDensity(liquidDensity);
    // double liquidPressure = liquidContainer.calculatePressure();
    // std::cout << "The pressure in the liquid container is: " << liquidPressure << " Pa" << std::endl;

    // GasContainer gasContainer;
    // double gasVolume, gasTemperature;
    // std::cout << "Enter the volume of the gas: ";
    // std::cin >> gasVolume;
    // std::cout << "Enter the temperature of the gas: ";
    // std::cin >> gasTemperature;
    // gasContainer.setVolume(gasVolume);
    // gasContainer.setTemperature(gasTemperature);
    // double gasPressure = gasContainer.calculatePressure();
    // std::cout << "The pressure in the gas container is: " << gasPressure << " Pa" << std::endl;

    // return 0;

		PressureMeasurement measurement;

    double fluidDensity, fluidHeight, objectDepth, gravity;
    std::cout << "Enter the density of the fluid (in kg/m^3): ";
    std::cin >> fluidDensity;
    std::cout << "Enter the height of the fluid (in meters): ";
    std::cin >> fluidHeight;
    std::cout << "Enter the depth of the object in the fluid (in meters): ";
    std::cin >> objectDepth;
    std::cout << "Enter the acceleration due to gravity (in m/s^2): ";
    std::cin >> gravity;

    measurement.setFluidDensity(fluidDensity);
    measurement.setFluidHeight(fluidHeight);
    measurement.setObjectDepth(objectDepth);
    measurement.setGravity(gravity);

    double pressure = measurement.calculatePressure();
    std::cout << "The pressure applied to the object in the fluid is: " << pressure << " Pa" << std::endl;

    return 0;
}