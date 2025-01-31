#include <iostream>

int main() {
	int tt;
	std::cin >> tt;
	int solution[tt];
	for (int t = 0; t < tt; t++) {
		int n, r;
		std::cin >> n >> r;
		
		int a[n];
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		int remainingSeats = r * 2;
		int happy = 0;
		for (int i = 0; i < n; i++) {
			happy += (a[i] / 2) * 2;
			remainingSeats -= (a[i] / 2) * 2;
			a[i] = a[i] % 2;
		}
		
		int remainingPeople = 0;
		for (int i = 0; i < n; i++) {
			remainingPeople += a[i];
		}
		
		for (int i = 0; remainingPeople > 0 && remainingSeats > remainingPeople; i++) {
			happy++;
			remainingSeats-=2;
			remainingPeople--;
		}
		solution[t] = happy;
	}
	
	for (int i = 0; i < tt; i++) std::cout << solution[i] << std::endl;
	return 0;
}
