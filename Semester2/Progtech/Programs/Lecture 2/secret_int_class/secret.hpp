#include <string>

class secret {
public:
    secret(const std::string &pwd, int d);
    int get(const std::string& pwd);
private:
    int data;
    std::string password;
};