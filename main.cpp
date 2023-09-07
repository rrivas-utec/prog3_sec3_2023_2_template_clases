#include <iostream>
#include "plantillas.h"

void ejemplo_atributos() {
    std::cout << A::y << std::endl;

    A obj_a;
    std::cout << obj_a.x << std::endl;

    typename A::TipoEntero z = 20;
    typename A::TipoTexto w = "Hola";
    std::cout << z << std::endl;
    std::cout << w << std::endl;

    if constexpr (son_iguales<A::TipoEntero, A::TipoTexto>::value) {
        std::cout << "Son iguales";
    }
    else {
        std::cout << "Son Diferentes";
    }

    if constexpr (son_iguales<A::TipoEntero, A::TipoEntero2>::value) {
        std::cout << "Son iguales";
    }
    else {
        std::cout << "Son Diferentes";
    }
}

template <typename ...Package>
auto sumar(Package... params) {
    static_assert(todos_iguales<Package...>::value);
    return (params + ...);
}

int main() {
    std::cout << sumar(10, 20, 30, 40);
//    ejemplo_atributos();
    return 0;
}
