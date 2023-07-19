#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура, яка представляє квартиру
typedef struct {
    int roomCount;
    int floor;
    float rentPrice;
} Apartment;

// Структура, яка представляє замовлення
typedef struct {
    int apartmentIndex;
    char city[50];
    int roomCount;
    int floor;
    float maxRentPrice;
} Order;

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

// Функція для виведення інформації про замовлення
void printOrder(Order order, Apartment *apartments, int numOfApartments) {
    printf("Місто: %s\n", order.city);
    printf("Кількість кімнат: %d\n", order.roomCount);
    printf("Поверх: %d\n", order.floor);
    printf("Максимальна ціна оренди: %.2f грн\n", order.maxRentPrice);

    if (order.apartmentIndex >= 0 && order.apartmentIndex < numOfApartments) {
        printf("Вибрана квартира:\n");
        printApartment(apartments[order.apartmentIndex]);
    } else {
        printf("Квартира не знайдена\n");
    }
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
    int numOfKyivApartments = sizeof(kyivApartments) / sizeof(kyivApartments[0]);

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
    };
    int numOfLvivApartments = sizeof(lvivApartments) / sizeof(lvivApartments[0]);

    Apartment odesaApartments[] = {
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
        createApartment(3, 5, 15000.0),
        createApartment(3, 4, 18000.0),
        createApartment(2, 4, 15000.0),
        createApartment(3, 9, 21000.0)
    };
    int numOfOdesaApartments = sizeof(odesaApartments) / sizeof(odesaApartments[0]);

    // Замовлення
    Order currentOrder;
    Order orderHistory[100];
    int numOfOrders = 0;
    
    // Вибірка квартир за критеріями
    int desiredRoomCount;
    int desiredFloor;
    float desiredRentPrice;

    printf("Введіть бажану кількість кімнат: ");
    scanf("%d", &desiredRoomCount);

    printf("Введіть бажаний поверх: ");
    scanf("%d", &desiredFloor);

    printf("Введіть максимальну ціну оренди: ");
    scanf("%f", &desiredRentPrice);

    // Пошук та виведення квартир, що задовольняють вказані критерії
    printf("Результати пошуку:\n");
    printf("Квартири в Києві:\n");
    for (int i = 0; i < numOfKyivvApartments; i++) {
        if (kyivvApartments[i].roomCount == desiredRoomCount &&
            kyivApartments[i].floor == desiredFloor &&
            kyivApartments[i].rentPrice <= desiredRentPrice) {
            printApartment(kievApartments[i]);
        }
    }
    printf("Квартири у Львові:\n");
    for (int i = 0; i < numOfLvivApartments; i++) {
        if (lvivApartments[i].roomCount == desiredRoomCount &&
            lvivApartments[i].floor == desiredFloor &&
            lvivApartments[i].rentPrice <= desiredRentPrice) {
            printApartment(lvivApartments[i]);
        }
    }

    printf("Квартири в Одесі:\n");
    for (int i = 0; i < numOfOdesaApartments; i++) {
        if (odesaApartments[i].roomCount == desiredRoomCount &&
            odesaApartments[i].floor == desiredFloor &&
            odesaApartments[i].rentPrice <= desiredRentPrice) {
            printApartment(odesaApartments[i]);
        }
    }

    return 0;
}
