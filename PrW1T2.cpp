#include <iostream>
struct ComplecsNumber
{
	double full = 0;
	double imaginary = 0;
	void Print() {
		std::cout << full << " + " << imaginary << "i";
	}
};
namespace Complecs {
	ComplecsNumber Sum(ComplecsNumber firstNumber, ComplecsNumber secondNumber) {
		ComplecsNumber result;
		result.full = firstNumber.full + secondNumber.full;
		result.imaginary = firstNumber.imaginary + secondNumber.imaginary;
		return result;
	}
	ComplecsNumber Multiply(ComplecsNumber firstNumber, ComplecsNumber secondNumber) {
		ComplecsNumber result;
		result.full = firstNumber.full * secondNumber.full - (firstNumber.imaginary * secondNumber.imaginary);
		result.imaginary = firstNumber.full * secondNumber.imaginary + secondNumber.full * firstNumber.imaginary;
		return result;
	}
	ComplecsNumber Devide(ComplecsNumber firstNumber, ComplecsNumber secondNumber) {
		ComplecsNumber complecsconjugate;
		complecsconjugate.full = secondNumber.full;
		complecsconjugate.imaginary = 0 - secondNumber.imaginary;
		ComplecsNumber numerator = Multiply(firstNumber, complecsconjugate);
		ComplecsNumber denominator = Multiply(secondNumber, complecsconjugate);

		ComplecsNumber result;
		result.full = numerator.full/denominator.full;
		result.imaginary = numerator.imaginary/denominator.full;
		return result;
	}
}
int main()
{
	ComplecsNumber number;
	number.full = 3;
	number.imaginary = 2;
	ComplecsNumber number1;
	number1.full = 1;
	number1.imaginary = -1;
	ComplecsNumber re = Complecs::Devide(number, number1);
	re.Print();
}