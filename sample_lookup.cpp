#include <iostream>
#include <string>
#include <unordered_map>

class PersonDir
{
  public:
    int lookup(const std::string &key) const noexcept
    {
        auto itr = my_store.find(key);
        if (itr != my_store.end())
        {
            return itr->second;
        }
    }

  private:
    std::unordered_map<std::string, int> my_store{ { "John", 49 }, { "Mike", 33 } };
};

int main()
{
    PersonDir dir;
    auto age = dir.lookup("Pratik");
    std::cout << "The key was found and the value stored is = " << age << "\n";

    return 0;
}