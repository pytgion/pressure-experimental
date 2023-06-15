#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>
#include <unordered_map>

class Material {
public:
    virtual void PrintDensity() const = 0;
};

class SolidDensity : public Material {
private:
    std::unordered_map<std::string, double> densities;

public:
    SolidDensity() {
        AddSolid("Iron", 7860.0);
        AddSolid("Copper", 8960.0);
        AddSolid("Aluminum", 2700.0);
        AddSolid("Wood", 700.0);
        AddSolid("Plastic", 1000.0);
        AddSolid("Gold", 19300.0);
        AddSolid("Silver", 10500.0);
        AddSolid("Lead", 11340.0);
        AddSolid("Brick", 2000.0);
        AddSolid("Concrete", 2400.0);
        AddSolid("Glass", 2500.0);
        AddSolid("Diamond", 3500.0);
        AddSolid("Granite", 2700.0);
        AddSolid("Quartz", 2650.0);
        AddSolid("Sapphire", 4000.0);
        // Diğer katı maddelerin yoğunluk değerlerini buraya ekleyebilirsiniz.
    }

    void AddSolid(const std::string& name, double density) {
        densities[name] = density;
    }

    void PrintDensity() const override {
        std::cout << "Solid Densities:" << std::endl;
        for (const auto& pair : densities) {
            std::cout << pair.first << ": " << pair.second << " kg/m³" << std::endl;
        }
    }
};

class LiquidDensity : public Material {
private:
    std::unordered_map<std::string, double> densities;

public:
    LiquidDensity() {
        AddLiquid("Water", 1000.0);
        AddLiquid("Milk", 1030.0);
        AddLiquid("Oil", 900.0);
        AddLiquid("Ethanol", 789.0);
        AddLiquid("Acetone", 790.0);
        AddLiquid("Glycerin", 1260.0);
        AddLiquid("Mercury", 13546.0);
        AddLiquid("Benzene", 876.0);
        AddLiquid("Ammonia", 682.0);
        AddLiquid("Hydrochloric Acid", 1180.0);
        AddLiquid("Sulfuric Acid", 1840.0);
        AddLiquid("Nitric Acid", 1510.0);
        AddLiquid("Carbon Tetrachloride", 1600.0);
        AddLiquid("Chloroform", 1490.0);
        AddLiquid("Turpentine", 865.0);
        // Diğer sıvı maddelerin yoğunluk değerlerini buraya ekleyebilirsiniz.
    }

    void AddLiquid(const std::string& name, double density) {
        densities[name] = density;
    }

    void PrintDensity() const override {
        std::cout << "Liquid Densities:" << std::endl;
        for (const auto& pair : densities) {
            std::cout << pair.first << ": " << pair.second << " kg/m³" << std::endl;
        }
    }
};

class GasDensity : public Material {
private:
    std::unordered_map<std::string, double> densities;

public:
    GasDensity() {
        AddGas("Air", 1.225);
        AddGas("Oxygen", 1.429);
        AddGas("Hydrogen", 0.0899);
        AddGas("Nitrogen", 1.165);
        AddGas("Carbon Dioxide", 1.98);
        AddGas("Helium", 0.1785);
        AddGas("Argon", 1.784);
        AddGas("Methane", 0.717);
        AddGas("Ammonia", 0.771);
        AddGas("Sulfur Dioxide", 2.927);
        AddGas("Chlorine", 3.214);
        AddGas("Neon", 0.9);
        AddGas("Xenon", 5.894);
        AddGas("Krypton", 3.749);
        AddGas("Radon", 9.73);
        // Diğer gaz maddelerin yoğunluk değerlerini buraya ekleyebilirsiniz.
    }

    void AddGas(const std::string& name, double density) {
        densities[name] = density;
    }

    void PrintDensity() const override {
        std::cout << "Gas Densities:" << std::endl;
        for (const auto& pair : densities) {
            std::cout << pair.first << ": " << pair.second << " kg/m³" << std::endl;
        }
    }
};

#endif