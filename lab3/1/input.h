#ifndef INPUT_H
#define INPUT_H


template <typename T> 
void input(T &n, const char * mess, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
    for (;;) {
        std::cin.clear();
        std::cout << mess << std::endl;
        if ((std::cin >> n).good()) {
            if (n <= max && n >= min) return;
            std::cout << "Invalid value\n";
        }
        if (std::cin.fail()) {
            std::cout << "Wrong input, repeat please.\n";

        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}



#endif