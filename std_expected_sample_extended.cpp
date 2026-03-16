#include <expected>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

enum class ErrorTypes
{
    KeyNotFound,
    InvalidInput,
    AgeDoesNotMatch
};

class PersonDir
{
  public:
    [[nodiscard]] std::expected<int, ErrorTypes> lookup(const std::string &key, int age) const noexcept
    {
        if (key.empty())
        {
            return std::unexpected(ErrorTypes::InvalidInput);
        }
        auto itr = my_store.find(key);
        if (itr != my_store.end())
        {
            if (itr->second != age)
            {
                return std::unexpected(ErrorTypes::AgeDoesNotMatch);
            }
            return itr->second;
        }

        return std::unexpected(ErrorTypes::KeyNotFound);
    }

  private:
    std::unordered_map<std::string, int> my_store{ { "John", 49 }, { "Mike", 33 } };
};

constexpr std::string_view to_string(ErrorTypes error) noexcept
{
    switch (error)
    {
    case ErrorTypes::KeyNotFound:
    {
        return "Key not found";
    }
    case ErrorTypes::InvalidInput:
    {
        return "Invalid Input";
    }
    case ErrorTypes::AgeDoesNotMatch:
    {
        return "Age doesn't match";
    }
    }

    return "Unknown error";
}

std::ostream &operator<<(std::ostream &os, ErrorTypes error)
{
    os << to_string(error);
    return os;
}

int main()
{
    PersonDir dir;
    auto result = dir.lookup("Pratik", 23);
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
