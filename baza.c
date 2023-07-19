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

    // Користувацьке меню
    int choice;
    do {
        printf("\n-------------------------\n");
        printf("Меню:\n");
        printf("1. Зробити нове замовлення\n");
        printf("2. Переглянути поточне замовлення\n");
        printf("3. Переглянути історію замовлень\n");
        printf("0. Вийти з програми\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Введення критеріїв замовлення
                printf("Введіть бажану кількість кімнат: ");
                scanf("%d", &desiredRoomCount);

                printf("Введіть бажаний поверх: ");
                scanf("%d", &desiredFloor);

                printf("Введіть максимальну ціну оренди: ");
                scanf("%f", &desiredRentPrice);
                // Пошук та виведення квартир, що задовольняють вказані критерії
                printf("Результати пошуку:\n");
                printf("Квартири в Києві:\n");
                for (int i = 0; i < numOfKyivApartments; i++) {
                    if (kyivApartments[i].roomCount == desiredRoomCount &&
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

  // Вибір квартири для замовлення
                printf("\nВведіть індекс квартири для замовлення (або -1 для скасування): ");
                scanf("%d", &currentOrder.apartmentIndex);

                if (currentOrder.apartmentIndex >= 0 && currentOrder.apartmentIndex < numOfKievApartments) {
                    // Збереження деталей замовлення
                    printf("Введіть місто для замовлення: ");
                    scanf("%s", currentOrder.city);
                    currentOrder.roomCount = desiredRoomCount;
                    currentOrder.floor = desiredFloor;
                    currentOrder.maxRentPrice = desiredRentPrice;

                    // Додавання замовлення до історії
                    orderHistory[numOfOrders] = currentOrder;
                    numOfOrders++;

                    printf("Замовлення розміщено.\n");
                } else {
                    printf("Замовлення скасовано.\n");
                }

                break;
        case 2:
                // Перегляд поточного замовлення
                if (currentOrder.apartmentIndex >= 0 && currentOrder.apartmentIndex < numOfKyivApartments) {
                    printf("Поточне замовлення:\n");
                    printOrder(currentOrder, kyivApartments, numOfKyivApartments);
                } else {
                    printf("Немає поточного замовлення.\n");
                }

                break;
            case 3:
                // Перегляд історії замовлень
                if (numOfOrders > 0) {
                    printf("Історія замовлень:\n");
                    for (int i = 0; i < numOfOrders; i++) {
                        printf("\nЗамовлення %d:\n", i + 1);
                        printOrder(orderHistory[i], kyivApartments, numOfKyivApartments);
                    }
                } else {
                    printf("Історія замовлень порожня.\n");
                }

                break;
            case 0:
                printf("Дякуємо за використання програми. До побачення!\n");
                break;
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}                
