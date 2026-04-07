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
    Restaurant() {}

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

    const char *toString(const Category &c) const
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
        std::println("{} - {} restaurant", name, toString(category));

        if (isOpen)
        {
            cout << "is open" << '\n';
        }
        else
            cout << "is closed" << '\n';

        std::println("Rating: {}, Average price: {}", rating, averagePrice);
    }
};

class RestaurantChain
{
private:
    Restaurant restaurants[MAX_NAME_LENGTH];
    int count = 0;

public:
    RestaurantChain(const Restaurant *restaurants, int count) : count(count)
    {
        if (count > MAX_NAME_LENGTH)
        {
            count = MAX_NAME_LENGTH;
        }

        for (int i = 0; i < count; i++)
        {
            this->restaurants[i] = restaurants[i];
        }
    }

    RestaurantChain(const Restaurant *restaurants, int counter, Category category)
    {
        for (int i = 0; i < counter; i++)
        {
            if (category == restaurants[i].getCategory())
            {
                this->restaurants[count] = restaurants[i];
                count++;
            }
        }
    }

    bool addRestaurant(const Restaurant &newRestaurant)
    {

        if (count >= 0 && count < MAX_NAME_LENGTH)
        {
            restaurants[count] = newRestaurant;
            count++;
            return true;
        }
        return false;
    }

    void removeRestaurant(const char *newName)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(restaurants[i].getName(), newName) == 0)
            {
                std::swap(restaurants[i], restaurants[--count]);
            }
        }
    }

    int getCount() const
    {
        return count;
    }

    void sortRestaurantsByPrice()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (restaurants[j].getAveragePrice() > restaurants[j + 1].getAveragePrice())
                {
                    std::swap(restaurants[j], restaurants[j + 1]);
                }
            }
        }
    }

    const Restaurant *getMostExpensive(int num)
    {
        sortRestaurantsByPrice();

        if (num > count)
            num = count;

        Restaurant *mostExpensive = new Restaurant[num];

        for (int i = 0; i < num; i++)
        {
            mostExpensive[i] = restaurants[count - num + i];
        }

        return mostExpensive;
    }

    void printOpen() const
    {
        for (int i = 0; i < count; i++)
        {
            if (restaurants[i].isOpened())
            {
                restaurants[i].print();
            }
            cout << '\n';
        }
    }

    void rateAll(double rating)
    {
        for (int i = 0; i < count; i++)
        {
            restaurants[i].setRate(rating);
            if (restaurants[i].getRating() < 1)
            {
                restaurants[i].close();
            }
        }
    }

    double getAveragePriceForCategory(Category category)
    {
        double sumAvg = 0;
        int counter = 0;

        for (int i = 0; i < count; i++)
        {
            if (restaurants[i].getCategory() == category)
            {
                sumAvg += restaurants[i].getAveragePrice();
                counter++;
            }
        }
        return sumAvg / counter;
    }
};