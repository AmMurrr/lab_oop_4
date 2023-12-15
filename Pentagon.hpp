#include "Figure.hpp"

template<class T>
class Pentagon : public Figure<T> {

    public:
        std::vector<std::pair<T,T>> cord;
        std::pair<T,T> mid;

        Pentagon() {
            mid = std::pair<double,double>{0,0};
            cord = {{0,0},{0,0},{0,0},{0,0},{0,0}}; // чекни без скобок круглых
        }
        ~Pentagon() {
            mid = {0,0};
            cord = {};
        }
        Pentagon(std::vector<std::pair<T,T>> coord) {
            cord = coord;
            mid = center();
        }
        Pentagon(const Pentagon<T> &other) {
            cord = other.cord;
            mid = other.mid;
        }

        Pentagon<T>& operator=( const Pentagon<T> &other) {
            cord = other.cord;
            mid = other.mid;
            return *this;
        }
        // https://cplusplus.com/forum/beginner/180106/
        Pentagon<T>& operator=( const Pentagon<T> &&other) {
            cord = std::move(other.cord);
            mid = std::move(other.mid);
            return *this;
        }
        bool operator==(Pentagon<T> &other) {
            if(cord = other.cord){ //working??
                return true;
            } else {
                return false;
            }
        }
        
        std::pair<T,T> center() const override {
            std::pair<T,T> cent;
            cent.first = (cord[0].first + cord[1].first + cord[2].first + cord[3].first + cord[4].first)/5;
            cent.second = (cord[0].second + cord[1].second + cord[2].second + cord[3].second + cord[4].second)/5;
            return cent;
        }

        T area() const override {
            T a = sqrt(pow(cord[0].first - cord[1].first, 2) + pow(cord[0].second - cord[1].second,2));
            T h = (0.5 * a) / (tan(M_PI/5));

            return 5 * (0.5*a*h);
            // T a = fabs(cord[1].second - cord[3].second);
            // T b = fabs(cord[2].first - cord[0].first);

            // return 0.5 * a * b; 
        }

        operator double() const override {
            return area();
        }       
};




template<class T>
inline std::ostream& operator<<(std::ostream &os, Pentagon<T> &fig) {
    for( int i = 0; i < 5; i++){
        os << i + 1 << "-ая точка: "<< '(' << fig.cord[i].first << ", " << fig.cord[i].second << ')' << '\n';
    }
    return os;
}

template<class T>
inline std::istream& operator>>(std::istream &is, Pentagon<T> &fig) {
    std::cout << "Точки вводятся с нижней левой по часовой стрелке" << '\n';
    for( int i = 0; i < 5; i++) {
        std::cout << "Введите "<< i + 1 << "-ую точку: "; 
        is >> fig.cord[i].first >> fig.cord[i].second;
        
    }
    return is;
}
