#include <iostream>
#include <print>
#include <cstring>
#pragma warning(disable : 4996)

const int MAX_NAME_LENGTH = 100;

using std::cin;
using std::cout;

enum class Category
{
    Italian,
    Chinese,
    American,
    French,
    Japanese
};

class Restaurant
{
private:
    char name[MAX_NAME_LENGTH];
    Category category;
    bool isOpen = true;
    double rating = 0;
    double averagePrice = 0;

public:
    Restaurant(const char *name, Category cat, double avgPrice)
    {
        strcpy(this->name, name);
        category = cat;
        averagePrice = avgPrice;
        isOpen = true;
        rating = 0;
    };

    const char *getName() const
    {
        return name;
    }

    Category getCategory() const
    {
        return category;
    }

    bool isOpened() const
    {
        return isOpen;
    }

    double getRating() const
    {
        return rating;
    }

    double getAveragePrice() const
    {
        return averagePrice;
    }

    void setRate(double newRating)
    {
        rating = (rating + newRating) / 2;
    }

    void open()
    {
        isOpen = true;
    }

    void close()
    {
        isOpen = false;
    }

    const char *categoryToString(const Category &c) const
    {
        switch (c)
        {
        case Category::Italian:
            return "Italian";
        case Category::Chinese:
            return "Chinese";
        case Category::American:
            return "American";
        case Category::French:
            return "French";
        case Category::Japanese:
            return "Japanese";
        default:
            return "Unknown";
        }
    }

    void print() const
    {
        std::println("{} - {} restaurant", name, categoryToString(category));

        if (isOpen)
        {
            cout << "is open" << '\n';
        }
        else
            cout << "is closed" << '\n';

        std::println("Rating: {}, Average price: {}", rating, averagePrice);
    }
};