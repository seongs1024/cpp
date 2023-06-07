#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data = {.value = 42};
	Data * serde = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "Data: " << &data << " | .value: " << data.value << std::endl;
	std::cout << "Serd: " << serde << " | .value: " << serde->value << std::endl;
	return 0;
}