#pragma once

class Product
{
private:
	char* name;
	int size;
	double price;
	static int count;
	int id;
	char* producer;

	void free();
	void copyFrom(const Product& other);
public:
	Product() = default;
	Product(const char* name, int size, double price, const char* producer);

	double getPrice() const;
	const char* getProducer() const;
	const char* getName() const;
	int getSize() const;
	int getId() const; // depending on implementation

	void setPrice(double price);
	void setProducer(const char* producer);
	void setName(const char* name);
	void setSize(int size);

	~Product();
	Product& operator=(const Product& other);
	Product(const Product& other);
};

