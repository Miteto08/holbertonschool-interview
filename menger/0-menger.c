#include "menger.h"

/**
 * print_level - Imprime un niveau de l'éponge de Menger
 * @size: Taille totale de l'éponge
 * @x: Position x actuelle
 * @y: Position y actuelle
 */
static void print_level(int size, int x, int y)
{
    if (size == 1)
    {
        printf("#");
        return;
    }

    int sub_size = size / 3;
    int is_center = (x >= sub_size && x < 2 * sub_size) &&
                    (y >= sub_size && y < 2 * sub_size);

    if (is_center)
    {
        printf(" ");
        return;
    }

    print_level(sub_size, x % sub_size, y % sub_size);
}

/**
 * menger - Dessine une éponge de Menger en 2D
 * @level: Niveau de l'éponge
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            print_level(size, x, y);
        }
        printf("\n");
    }
}
