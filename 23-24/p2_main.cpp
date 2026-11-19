#include <iostream>
#include <vector>
#include "Person.cpp"
#include "Date.cpp"

void born_before(const std::vector<Person>& persons, const Date& date) {
    for (const Person& person : persons) {
        if (person.get_birthdate() < date) {
            std::cout << "Name: " << person.get_name() << ", Birthdate: ";
            person.get_birthdate().write(); // Assuming Date::write() function prints the date
            std::cout << std::endl;
        }
    }
}

int main() {
    // Example usage
    std::vector<Person> persons = {
        Person("John", Date(1990, 5, 15)),
        Person("Alice", Date(1985, 8, 20)),
        Person("Bob", Date(1978, 3, 10))
    };

    Date date_to_compare(1980, 1, 1);

    std::cout << "Persons born before ";
    date_to_compare.write(); // Assuming Date::write() function prints the date
    std::cout << ":" << std::endl;

    born_before(persons, date_to_compare);

    return 0;
}