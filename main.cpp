#include <memory.h>
#include "Figure.hpp"
#include "Trapezoid.hpp"
#include "Rombus.hpp"
#include "Pentagon.hpp"
#include "array.hpp"


int main(int argc, char const *argv[])
{
     array<std::shared_ptr<Figure<double>>> arr(3);

     Trapezoid<double> trap;
     Rombus<double> robux;
     Pentagon<double> penta;

     std::cin >> trap;
//   std::cin >> rob;
//   std::cin >> penta;

     std::shared_ptr<Figure<double>> tr = std::make_shared<Trapezoid<double>>(trap); 
     arr.add_figure(0, tr);
     std::shared_ptr<Figure<double>> rb = std::make_shared<Rombus<double>>(robux); 
     arr.add_figure(1, rb);
     std::shared_ptr<Figure<double>> pt = std::make_shared<Pentagon<double>>(penta); 
     arr.add_figure(2, pt);

    std::cout << "Трапеция" << std::endl;
    std::cout << "Площадь: " << arr[0]->area() << std::endl;
    std::cout << "Центр: " << arr[0]->center().first << ' ' << arr[0]->center().second << std::endl;
    std::cout << trap;

    std::cout << "Ромбус" << std::endl;
    std::cout << "Площадь: " << arr[1]->area() << std::endl;
    std::cout << "Центр: " << arr[1]->center().first << ' ' << arr[1]->center().second << std::endl;
    std::cout << robux;

    std::cout << "Пятиулогльник" << std::endl;
    std::cout << "Площадь: " << arr[2]->area() << std::endl;
    std::cout << "Центр: " << arr[2]->center().first << ' ' << arr[2]->center().second << std::endl;
    std::cout << penta;

    double tot_area = 0.0;
    std::cout << "Общая площадь" << std::endl;
    for(size_t j = 0; j < 3;j++)
        tot_area += arr[j]->area();
    std::cout << tot_area << std::endl;

    

    return 0;
}