#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
struct Info
{
    std::string name;
    double telNum;
    std::string street;
    std::string city;
    std::string state;
    std::string zipC;
    Info(std::string name_, double telNum_, std::string street_,
        std::string city_, std::string state_, std::string zipC_)
        : name(name_), telNum(telNum_), street(street_),
        city(city_), state(state_), zipC(zipC_)
    {
    }
    friend std::ostream &operator<<(std::ostream &o, const Info &i)
    {
        return o << "name   = " << i.name << '\n'
                << "telNum = " << i.telNum << '\n'
                << "street = " << i.street << '\n'
                << "city   = " << i.city << '\n'
                << "state  = " << i.state << '\n'
                << "zipC   = " << i.zipC << '\n';
    }
};
int main()
{
    const Info Dave("Dave", 1234.5678, "Main St.", "Center City", "MN", "12345");
    const Info Jenny("Jenny", 867.5309, "Broadway", "Spatula City", "WY", "90210");
    // Show each individually:
    std::cout << Dave << '\n';
    std::cout << Jenny << '\n';
    // Fill a vector...
    std::vector<Info> data;
    data.push_back(Dave);
    data.push_back(Jenny);
    // ... and output all vector elements:
    std::copy(data.begin(), data.end(),
    std::ostream_iterator<Info>(std::cout, "\n"));
    return 0;
}