#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура, яка представляє квартиру
typedef struct {
    int roomCount;
    int floor;
    float rentPrice;
} Apartment;

// Функція для створення нової квартири
Apartment createApartment(int roomCount, int floor, float rentPrice) {
    Apartment apt;
    apt.roomCount = roomCount;
    apt.floor = floor;
    apt.rentPrice = rentPrice;
    return apt;
}
// Функція для виведення інформації про квартиру
void printApartment(Apartment apt) {
    printf("( %d поверх, %d кімнати, ціна %.2f грн/міс )\n", apt.floor, apt.roomCount, apt.rentPrice);
}

int main() {
    // База даних квартир
    Apartment kyivApartments[] = {
        createApartment(1, 1, 12000.0),
        createApartment(2, 1, 14500.0),
        createApartment(3, 1, 1800.0),
        createApartment(1, 2, 13000.0),
        createApartment(2, 2, 15000.0),
        createApartment(3, 2, 19000.0),
        createApartment(1, 3, 13800.0),
        createApartment(2, 3, 16000.0),
        createApartment(3, 3, 19000.0)
    };
    int numOfKievApartments = sizeof(kievApartments) / sizeof(kievApartments[0]);

    Apartment lvivApartments[] = {
        createApartment(1, 1, 12000.0),
        createApartment(2, 1, 14500.0),
        createApartment(3, 1, 1800.0),
        createApartment(1, 2, 13000.0),
        createApartment(2, 2, 15000.0),
        createApartment(3, 2, 19000.0),
        createApartment(1, 3, 13800.0),
        createApartment(2, 3, 16000.0),
        createApartment(3, 3, 19000.0),
        createApartment(4, 1, 17000.0),
        createApartment(2, 3, 13000.0),
        createApartment(3, 5, 15000.0)
    }
