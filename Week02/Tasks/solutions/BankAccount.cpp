#include <iostream>
#include <fstream>

namespace constants {
    const size_t MAX_NAME_LENGTH = 50;
    const double MIN_BALANCE = 0.0;
    const size_t IBAN_SIZE = 16;
    const double MIN_DEPOSIT = 0.0;
};

enum class Currency {
    USD,
    EUR,
    GBP,
    BTC,
    ARS,
    UNKNOWN
};

struct BankAccount {
    char name[constants::MAX_NAME_LENGTH];
    double balance;
    char IBAN[constants::IBAN_SIZE];

    void deposit(double amount) {
        if (amount <= constants::MIN_DEPOSIT) {
            std::cout << "Invalid deposit amount." << std::endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < constants::MIN_BALANCE || amount > balance) {
            std::cout << "Invalid withdrawal amount." << std::endl;
            return;
        }
        balance -= amount;
    }

    void display() const {
        display(Currency::EUR);
    }

    void display(Currency currency) const {
        std::cout << "Account Holder: " << name << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "IBAN: " << IBAN << std::endl;
        switch (currency) {
            case Currency::USD:
                std::cout << "Currency: USD" << std::endl;
                break;
            case Currency::EUR:
                std::cout << "Currency: EUR" << std::endl;
                break;
            case Currency::GBP:
                std::cout << "Currency: GBP" << std::endl;
                break;
            case Currency::BTC:
                std::cout << "Currency: BTC" << std::endl;
                break;
            case Currency::ARS:
                std::cout << "Currency: ARS" << std::endl;
                break;
            default:
                std::cout << "Currency: UNKNOWN" << std::endl;
        }
    }
};

class BankAccountSerializer {
public:
    void serialize(const BankAccount& account, const char* filename) { //може да се реши и чрез const std::string& filename -> не забравяйте референция!
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ofstream ofs(filename);
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs << account.name << std::endl << account.balance << std::endl << account.IBAN << std::endl;
        ofs.close();
    }

    /* Ако имаме подаден поток, отворен извън функцията, обикновено не затваряме потока, тъй като не сме ние тези, които го "притежават"
    void serialize(const BankAccount& account, std::ofstream& ofs) {
        if (!ofs.is_open()) {
            std::cout << "Error opening file for writing" << std::endl;
            return;
        }

        ofs << account.name << std::endl << account.balance << std::endl << account.IBAN << std::endl;
    }
    */

    // пример с std::string, може да се направи с const char* filename както serialize -> в този случай ще имаме nullptr проверка
    BankAccount deserialize(const std::string& filename) {
        BankAccount account;
        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            std::cout << "Error opening file "<< std::endl;
            return account;
        }

        ifs >> account.name >> account.balance >> account.IBAN;
        ifs.close();
        return account;
    }

    /* Отново, ако потока е отворен извън функцията, не го затваряме, освен ако не ни е казано
    BankAccount deserialize(const std::string& filename, std::ifstream& ifs) {
        BankAccount account;
        if (!ifs.is_open()) {
            std::cout << "Error opening file "<< std::endl;
            return account;
        }
        
        ifs >> account.name >> account.balance >> account.IBAN;
        return account;
    }
    */
};