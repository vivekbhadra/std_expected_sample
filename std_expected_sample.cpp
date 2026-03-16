#include <expected>
#include <iostream>
#include <string>
#include <unordered_map>

class PersonDir
{
  public:
    [[nodiscard]] std::expected<int, std::string> lookup(const std::string &key) const noexcept
    {
        auto itr = my_store.find(key);
        if (itr != my_store.end())
        {
            return itr->second;
        }

        return std::unexpected(std::string{ "Key Not Found" });
    }

  private:
    std::unordered_map<std::string, int> my_store{ { "John", 49 }, { "Mike", 33 } };
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
        std::cout << result.error() << "\n";
    }

    return 0;
}