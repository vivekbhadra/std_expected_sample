#include <iostream>
#include <map>
#include <optional>
#include <string>

class PersonDir
{
  public:
    std::optional<int> lookup(const std::string &key) const
    {
        auto itr = my_store.find(key);
        if (itr != my_store.end())
        {
            return itr->second;
        }

        return std::nullopt;
    }

  private:
    std::map<std::string, int> my_store{ { "John", 49 }, { "Mike", 33 } };
};

int main()
{
    PersonDir dir;
    auto result = dir.lookup("Pratik");
    if (result.has_value())
    {
        std::cout << "Key was found in the database and the value is " << *result << "\n";
    }
    else
    {
        std::cout << "Key wasn't found in the database\n";
    }

    return 0;
}