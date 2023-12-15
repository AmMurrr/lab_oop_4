#include "Figure.hpp"

template<class T>
class Rombus : public Figure<T> {

    public:
        std::vector<std::pair<T,T>> cord;
        std::pair<T,T> mid;

        Rombus() {
            mid = std::pair<double,double>{0,0};
            cord = {{0,0},{0,0},{0,0},{0,0}}; // чекни без скобок круглых
        }
        ~Rombus() {
            mid = {0,0};
            cord = {};
        }
        Rombus(std::vector<std::pair<T,T>> coord) {
            cord = coord;
            mid = center();
        }
        Rombus(const Rombus<T> &other) {
            cord = other.cord;
            mid = other.mid;
        }

        Rombus<T>& operator=( const Rombus<T> &other) {
            cord = other.cord;
            mid = other.mid;
            return *this;
        }
        Rombus<T>& operator=( const Rombus<T> &&other) {
            cord = std::move(other.cord);
            mid = std::move(other.mid);
            return *this;
        }
        bool operator==(Rombus<T> &other) {
            if(cord = other.cord){ //working??
                return true;
            } else {
                return false;
            }
        }
        
        std::pair<T,T> center() const override {
            std::pair<T,T> cent;
            cent.first = (cord[0].first + cord[1].first + cord[2].first + cord[3].first )/4;
            cent.second = (cord[0].second + cord[1].second + cord[2].second + cord[3].second)/4;
            return cent;
        }

        T area() const override {
            T a = fabs(cord[1].second - cord[3].second);
            T b = fabs(cord[2].first - cord[0].first);

            return 0.5 * a * b; 
        }

        operator double() const override {
            return area();
        }       
};




template<class T>
inline std::ostream& operator<<(std::ostream &os, Rombus<T> &fig) {
    for( int i = 0; i < 4; i++){
        os << i + 1 << "-ая точка: "<< '(' << fig.cord[i].first << ", " << fig.cord[i].second << ')' << '\n';
    }
    return os;
}

template<class T>
inline std::istream& operator>>(std::istream &is, Rombus<T> &fig) {
    std::cout << "Точки вводятся с нижней левой по часовой стрелке" << '\n';
    for( int i = 0; i < 4; i++) {
        std::cout << "Введите "<< i + 1 << "-ую точку: "; 
        is >> fig.cord[i].first >> fig.cord[i].second;
        
    }
    return is;
}
