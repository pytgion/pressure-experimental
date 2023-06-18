#include <iostream>
#include "experiment.hpp"

int main() {
    Experiment experiment;
    int choice;
    
    std::cout << "Su cenderesi testine hoş geldiniz!" << std::endl;

    while (true) {
        std::cout << "1. Yeni obje ekle\n";
        std::cout << "2. Değerleri göster\n";
        std::cout << "3. Çıkış\n";
        std::cout << "Seçiminizi yapın: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double w, s, h;
                std::cout << "Ağırlığı girin: ";
                std::cin >> w;
                std::cout << "Yüzey alanını girin: ";
                std::cin >> s;
                std::cout << "Yüksekliği girin: ";
                std::cin >> h;

                experiment.addValue(w, s);
                std::cout << "Yeni obje eklendi." << std::endl;
                break;
            }
            case 2:
                std::cout << std::endl << "Değerler:" << std::endl;
                experiment.printValues();
                break;
            case 3:
                std::cout << "Programdan çıkılıyor." << std::endl;
                return 0;
            case 4:
            {
                std::cout << "Cendere simülasyonu" << std::endl ;
                if (experiment.getCount() > 0) {
                    std::thread experimentThread(&Experiment::calculateHeight, std::ref(experiment));
                    experimentThread.join();
                }
                else {
                    std::cout << "Önce en az bir obje eklemeniz gerekmektedir." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Geçersiz seçim! Lütfen geçerli bir seçenek girin." << std::endl;
                break;
        }
    }

    return 0;
}
