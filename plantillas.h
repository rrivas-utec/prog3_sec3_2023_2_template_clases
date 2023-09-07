//
// Created by rrivas on 07/09/2023.
//

#ifndef PROG3_SEC3_2023_2_TEMPLATE_CLASES_PLANTILLAS_H
#define PROG3_SEC3_2023_2_TEMPLATE_CLASES_PLANTILLAS_H

#include<string>

// Ejemplo de atributos de clase y de instancia
struct A {
    int x = 11;                 // Atributo de instancia
    inline static int y = 22;   // Atributo de clase
    using TipoEntero = int;
    using TipoEntero2 = int;

    using TipoTexto = std::string;
};

template<class T1, class T2>
struct son_iguales {
    static constexpr bool value = false;
};

template<class T>
struct son_iguales<T, T> {
    static constexpr bool value = true;
};

template <class First, class ...Package>
struct todos_iguales {
    static constexpr bool value = (son_iguales<First, Package>::value && ...);
};


#endif //PROG3_SEC3_2023_2_TEMPLATE_CLASES_PLANTILLAS_H
