#include <iostream>
#include <vector>
#include <math.h>
#include <numbers>
#include <iomanip>


#include "Time.h"

namespace Nabeja {

	float Function(const double Value) {
		return (std::sin(Value) - (Value / 2));
	}

	float New_Xn(const double a, const double b) {
		return (a * Function(b) - b * Function(a)) / (Function(b) - Function(a));
	}
}

namespace Tansif {

	float function(const double value) {
		return (3 * value) - (std::pow(std::numbers::e, (-1 * value)));
	}

	float New_N(const double a, const double b) {
		return (a + b) / 2;
	}


}

namespace NewTon_Rafson {

	double Function(const double value) {
		return (std::sin(value) - (value / 2));
	}

	double Function_Prime(const double Value) {
		return (std::cos(Value) - 0.5);
	}


	double New_Xn(const double Value) {
		return Value - (Function(Value) / Function_Prime(Value));
	}

}

void Title() {
	std::system("cls");

	std::cout.setf(std::ios::boolalpha);
	std::cout.setf(std::ios::showbase);
	std::cout.setf(std::ios::showpoint);
	std::cout << std::setw(10) << std::left << "Count";
	std::cout << std::setw(10) << std::left << "A";
	std::cout << std::setw(10) << std::left << "B";
	std::cout << std::setw(10) << std::left << "Xn";
	std::cout << std::setw(15) << std::left << "F(Xn)";
	std::cout << std::setw(20) << std::left << "F(a).F(b) < 0";
	std::cout << std::left << "\n----------------------------------------------------------\n";

}


int main() {
	
	int count = 1;
	short choose;
	double a, b, Xn, FX_n, finalA{}, finalB, finalXn;
	double Limite = 0.001;	//	default
	
	Time t;

	std::cout << "1 - Nabeja \n2 - Tansif \n3 - NewTon-Rafson\nChoose : ";
	std::cin >> choose;

	
	switch (choose)
	{
	case 1: {

		std::cout << "Enter a , b : ";
		std::cin >> a >> b;

		std::cout << "Enter the Limite : ";
		std::cin >> Limite; 

		Title();
		
		while (true and count < 100) {

			auto Xn = Nabeja::New_Xn(a, b);
			auto FX_n = Nabeja::Function(Xn);
			bool Less = (Nabeja::Function(a) * Nabeja::Function(b)) < 0;

			std::cout << std::setw(10) << std::left << count++;
			std::cout << std::setw(10) << std::left << a;
			std::cout << std::setw(10) << std::left << b;
			std::cout << std::setw(10) << std::left << Xn;
			std::cout << std::setw(15) << std::left << FX_n;
			std::cout << std::setw(20) << std::left << Less << '\n';

			if (std::abs(FX_n) < Limite) {

				if (a < b) {
					finalA = a;
					finalB= b;
				}
				else {
					finalA = b;
					finalB = a;
				}
				finalXn = FX_n;
				break;

			}


			if ((Nabeja::Function(a) * Nabeja::Function(b)) < 0)
				b = Xn;
			else
				a = Xn;

			t.Sleep(100);
		}


	}		break;

	case 2: {


		std::cout << "Enter a , b :";
		std::cin >> a >> b;

		using Tansif::function;
		using Tansif::New_N;

		Title();

		while (true and count < 1001) {

			Xn = New_N(a, b);
			FX_n = function(Xn);

			bool Less = function(a) * function(b) < 0;

			std::cout << std::setw(10) << std::left << count++;
			std::cout << std::setw(10) << std::left << a;
			std::cout << std::setw(10) << std::left << b;
			std::cout << std::setw(10) << std::left << Xn;
			std::cout << std::setw(15) << std::left << FX_n;
			std::cout << std::setw(20) << std::left << Less << '\n';


			if (std::abs(FX_n) < Limite) {
			
				finalA = a;
				finalB = b;
				finalXn = Xn;
				
				break;
			}

			if (Less)
				b = Xn;
			else
				a = Xn;

			t.Sleep(100);
			count++;

		}//	end while

	}		break;

	case 3: {

		double x0 = 1.75;
		
		std::cout << "Enter a , b :";
		std::cin >> a >> b;
		
		std::cout << "Enter x0 : ";
		std::cin >> x0;

		std::cout << "Limite : ";
		std::cin >> Limite;


		Title();

		while (true and count < 1001) {

			Xn = NewTon_Rafson::New_Xn(x0);

			FX_n = NewTon_Rafson::Function(Xn);
			
			bool less = NewTon_Rafson::Function(a) * NewTon_Rafson::Function(b) < 0;

			std::cout << std::setw(10) << std::left << count++;
			std::cout << std::setw(10) << std::left << a;
			std::cout << std::setw(10) << std::left << b;
			std::cout << std::setw(10) << std::left << Xn;
			std::cout << std::setw(15) << std::left << FX_n;
			std::cout << std::setw(20) << std::left << less << '\n';
			




			if (std::abs(FX_n) < Limite) {
				finalXn = Xn;
				finalA = x0;
				finalB = 0;
				break;
			}
			x0 = Xn;


			t.Sleep(100);
		}//	end while


	}		break;

	default:	std::cout << "Wrong Number try again!\n\a";
	}//	end switch



	std::cout << "\n\n";
	std::cout << std::setw(10) << std::left << "A";
	std::cout << std::setw(10) << std::left << "B";
	std::cout << std::setw(10) << std::left << "Xn\n--------------------------------\n";

	std::cout << std::setw(10) << std::left << finalA;
	std::cout << std::setw(10) << std::left << finalB;
	std::cout << std::setw(10) << std::left << finalXn;

	std::cout << "\n\n";

}







class Base {
public:
	unsigned short Counter = 0;

	Base() {
		a = b = Limite = 0;
	}
	Base(const float const& ta, const float const &tb , const double const &Tlimite) {
		Set_AB(ta, tb);
		Set_Limite(Tlimite);
	}
		
	void Set_AB(const double const& ta, const double const& tb) {
		if (ta > tb)
			throw("Error a is bigger than b!\a\n");

		a = ta;
		b = tb;
	}

	void Set_Limite(const double const& Temp_Limite) {
		Limite = Temp_Limite;
	} 

	double Get_A()const {
		return a;
	}

	double Get_B()const {
		return b;
	}

	double B_Get_Limite()const {
		return Limite;
	}

private:
	double a, b, Limite;

};


class Tansif : private Base {

public:

	Tansif(){
		xn = 0;
		fxn = 0;
	}

	Tansif(const double const& a, const double const& b, const double const& tlimite) : Base(a, b, tlimite) {}

	~Tansif() {

	
		std::cout << std::setw(10) << std::left << Get_A();
		std::cout << std::setw(10) << std::left << Get_B();
		std::cout << std::setw(10) << std::left << xn;
		std::cout << std::setw(10) << std::left << fxn << '\n';

	}

	
	
	
	void Print(){


		std::cout << std::setw(10) << std::left << Get_A();
		std::cout << std::setw(10) << std::left << Get_B();
		std::cout << std::setw(10) << std::left << xn;
		std::cout << std::setw(15) << std::left << fxn;
		std::cout << std::setw(20) << std::left << Function(Get_A()) * Function(Get_B()) << '\n';

	}




	double Function(const double const& num) {
		xn = (3 * num) - (std::pow(std::numbers::e, (-1 * num)));
		return xn;
	}

	double New_XN() {
		++Counter;
		return (Get_A() + Get_B()) / 2;
	}


	void Set_A_B(const double const& a, const double const& b) {
		Set_AB(a, b);
	}
	
	void Set_Limite(const double const& tLimite) {
		Set_Limite(tLimite);
	}



	double Get_Limite()const {
		return B_Get_Limite();
	}
	double Get_A()const {
		return Base::Get_A();
	}

	double Get_B()const {
		return Base::Get_B();
	}


private:
	void Title()const {

		std::cout << std::setw(10) << std::left << "A";
		std::cout << std::setw(10) << std::left << "B";
		std::cout << std::setw(10) << std::left << "xn";
		std::cout << std::setw(15) << std::left << "F(xn)";
		std::cout << std::setw(20) << std::left << "F(a).F(b) < 0" << '\n';

	}

private:
	double xn , fxn;

};


int main() {

	double a, b, limite;

	std::cout << "Enter a , b , limite : ";
	std::cin >> a >> b >> limite;

	Tansif tansif(a, b, limite);
	
	while (true) {


		auto xn = tansif.New_XN();
		auto fxn = tansif.Function(xn);

		
		tansif.Print();


		if (std::abs(fxn) < tansif.Get_Limite())
			break;

		if (true)
			tansif.Set_A_B(tansif.Get_A(), xn);
		else
			tansif.Set_A_B(xn, tansif.Get_B());

	}


}