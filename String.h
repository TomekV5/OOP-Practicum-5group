#pragma once
class String
{
private:
	size_t size;
	char* data = nullptr;
	size_t capacity;
    void movefrom(String&& other);
	void copyfrom(const String& other);
	void free();
	void resize(size_t newCap);
public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();
    size_t length() const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    void push_back(char c);
    String& operator+=(const String& other);
    bool operator==(const String& other) const;
    const char* print() const;
};
String operator+(const String& a, const String& b);