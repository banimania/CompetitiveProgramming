#include <iostream>
#include <iomanip>

int main() {
	int n;
	std::cin >> n;
	
	float suma = 0.0f;
	int aprobados = 0;
	
	for (int i = 0; i < n; i++) {
		double nota = 0;
		std::cin >> nota;
		if (nota >= 5.0f) {
			suma += nota;
			aprobados++;
		}
	}
	
	std::cout << std::fixed << std::setprecision(2) << ((float) suma / aprobados);
	
	return 0;
}
