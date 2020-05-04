#include <stdexcept>
#include "CalculadoraSimples.hpp"

int CalculadoraSimples::Soma(int x, int y) {
	return (x + y);
}

int CalculadoraSimples::Subtrai(int x, int y) {
	return (x - y);
}

int CalculadoraSimples::Multiplicacao(int x, int y) {
	return (x * y);
}

int CalculadoraSimples::DivisaoInteira(int x, int y) {
	if (y == 0)
        throw std::overflow_error("Divisão por zero!");
    
    return x / y;
}