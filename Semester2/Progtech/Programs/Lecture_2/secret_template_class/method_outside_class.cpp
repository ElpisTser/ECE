#include <iostream>
#include <string>
#include <cstdlib>

template <typename T> // 1. `T` is a placeholder type, like a variable for a type
class secret{         // 2. `secret<T>` becomes a class for whatever type `T` you choose  
public:
    secret(const std::string &pwd,const T &d):
        password(pwd), data(d) {}
    T get(const std::string &pwd); // 3. Declare the get() method **inside the class**
private:
    T data;         
    std::string password;
};

// 4. Repeat the template declaration here
template <typename T>  
// 5. Use the syntax `ClassName<T>::MethodName` to indicate this method
//    belongs to the template class secret<T>
T secret<T>::get(const std::string &pwd) {
    if (password == pwd) return data;
    std::cout << "Wrong password" << std::endl;
    std::exit(0);
}

int main() {
    // Create a `secret` holding an int
    secret<int> s1("bababubu", 1999);
    // Create a `secret` holding a string
    secret<std::string> s2("bibibobo", "elpis");

    std::string p1, p2;
    
    std::cout << "Give password 1: ";
    std::cin >> p1;

    std::cout << "Give password 2: ";
    std::cin >> p2;

    std::cout << "S1 data: " << s1.get(p1) << std::endl;
    std::cout << "S2 data: " << s2.get(p2) << std::endl;   
}