#include <iostream>
#include <fstream>
const int MAX_ACCOUNT_NAME = 100;
const int MAX_IBAN_NUMBER = 34;
const int BUFF_SIZE = 100;
const int MAX_DEPOSIT_SIZE = 20;
double stringToDouble(char* str, int len) {
	double result = 0;
	bool passed = false;
	int couter = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '.') {
			passed = true;
		}
		else {
			result = result * 10 + ((int)str[i] - (int)'0');
		}
		if (passed) {
			couter++;
		}
	}
	for (int i = 0; i < couter - 1; i++) {
		result /= 10;
	}
	return result;
}
class BankAccount
{
private:
	char accountNumber[MAX_ACCOUNT_NAME]{ '\0' };
	double balance = 0;
	char iban[MAX_IBAN_NUMBER + 1]{ '\0' };
public:
	bool setAccount(char* input) {

		if(input[0] == '\0') {
			return false;
		}
		int index = 0;
		int tempindex = 0;
		while (input[index] != '\0' && input[index] != ',') {
			accountNumber[tempindex] = input[index];
			tempindex++;
			index++;
		}
		accountNumber[tempindex] = '\0';
		tempindex = 0;
		index++;
		char tempbalance[MAX_DEPOSIT_SIZE]{ '\0' };
		while (input[index] != '\0' && input[index] != ',') {
			tempbalance[tempindex] = input[index];
			index++;
			tempindex++;
		}
		tempbalance[tempindex] = '\0';
		balance = stringToDouble(tempbalance, tempindex);
		tempindex = 0;
		index++;
		while (input[index] != '\0') {
			iban[tempindex] = input[index];
			tempindex++;
			index++;
		}
		iban[tempindex] = '\0';
		return true;
	}
	bool draw(double amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			return true;
		}
		return false;
	}
	bool deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
			return true;
		}
		return false;
	}
	double getBalance(char currency[4]) const
	{
		if (currency == "USD")
		{
			return balance * 1.16; // Assuming a conversion rate of 1 EUR = 1.1 USD
		}
		else if (currency == "GBP")
		{
			return balance * 0.87; // Assuming a conversion rate of 1 EUR = 0.9 GBP
		}
		else if (currency == "ARS") {
			return balance * 1642.73; // Assuming a conversion rate of 1 EUR = 100 ARS
		}
		else if (currency == "BTC") {
			return balance * 0.000017; // Assuming a conversion rate of 1 EUR = 0.00002 BTC
		}
		else {
			return balance;
		}
	}
	char* getAccountInfo() const
	{
		char* info = new char[MAX_ACCOUNT_NAME + MAX_IBAN_NUMBER + MAX_DEPOSIT_SIZE];
		snprintf(info, MAX_ACCOUNT_NAME + MAX_IBAN_NUMBER + MAX_DEPOSIT_SIZE, "%s,%.2f,%s", accountNumber, balance, iban);
		return info;
	}
};
class BankAccountSerializer {
public:
	BankAccount* readFromFile(const char* filename,int& size) {
		std::ifstream inputfile(filename);
		if (!inputfile.is_open()) {
			std::cout << "Failed to open file." << std::endl;
		}
		inputfile.seekg(0, std::ios::beg);
		size = 0;
		while (!inputfile.eof()) {
			size++;
			char buff[BUFF_SIZE];
			inputfile.getline(buff, BUFF_SIZE);
		}
		inputfile.seekg(0, std::ios::beg);
		BankAccount* acounts = new BankAccount[size];
		int index = 0;
		while (!inputfile.eof()) {
			char buff[BUFF_SIZE];
			inputfile.getline(buff, BUFF_SIZE);
			acounts[index].setAccount(buff);
			index++;
		}
		inputfile.close();
		return acounts;
	}
	void printAccounts(BankAccount* accounts, int size) {
		for (int i = 0; i < size; i++) {
			char* info = accounts[i].getAccountInfo();
			std::cout << info << std::endl;
			delete[] info;
		}
	}
	bool writeToFile(const char* filename, BankAccount* accounts, int size) {
		std::ofstream outputfile(filename);
		if (!outputfile.is_open()) {
			std::cout << "Failed to open file." << std::endl;
			return false;
		}
		outputfile.seekp(0, std::ios::beg);
		for (int i = 0; i < size; i++) {
			char* info = accounts[i].getAccountInfo();
			if (i != size - 1) {
				outputfile << info << std::endl;
			}
			else {
				outputfile << info;
			}
			delete[] info;
		}
		outputfile.close();
		return true;
	}
};
int main()
{
	int size = 0;
	BankAccountSerializer serializer;
	BankAccount* accounts=serializer.readFromFile("accountinfo.txt",size);
	accounts[0].deposit(100);
	accounts[1].draw(50);
	serializer.printAccounts(accounts, size);
	serializer.writeToFile("accountinfo.txt", accounts, size);
	delete[] accounts;
}