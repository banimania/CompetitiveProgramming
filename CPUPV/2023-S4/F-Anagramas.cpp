#include <iostream>
#include <map>

int main(int argc, char** argv) {
	std::string s1;
	std::string s2;
	
	std::cin >> s1;
	std::cin >> s2;
	
	std::map<char, int> letras1;
	std::map<char, int> letras2;
	
	for (int i = 0; i < s1.length(); i++) {
		if (letras1.find(s1[i]) != letras1.end()) {
			letras1[s1[i]]++;
		} else letras1[s1[i]] = 1;
	}
	
	for (int i = 0; i < s2.length(); i++) {
		if (letras2.find(s2[i]) != letras2.end()) {
			letras2[s2[i]]++;
		} else letras2[s2[i]] = 1;
	}
	
	bool anagrama = letras1.size() == letras2.size();
	
	if (anagrama) {
		for (std::pair<char, int> par : letras1) {
			if (!anagrama) break;
			if (letras2.find(par.first) == letras2.end()) anagrama = false;
			else {
				if (letras2[par.first] != par.second) anagrama = false;
			}
		}
	}
	
	std::cout << (anagrama ? "YES" : "NO") << std::endl;
	
	return 0;
}
