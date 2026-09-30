#include <stdio.h>
#include <stdlib.h>

// Struktura pojedynczego wêz³a drzewa
struct drzewo
{
    int liczba;
    struct drzewo *l, *p;
};

// Funkcja dodaj¹ca element do drzewa
struct drzewo* wstaw(struct drzewo *korzen, int liczba)
{
    // Sprawdza, czy miejsce jest puste
    if (korzen == NULL)
    {
        struct drzewo *nowy =
            (struct drzewo*)malloc(sizeof(struct drzewo));

        nowy->liczba = liczba;
        nowy->l = NULL;
        nowy->p = NULL;

        return nowy;
    }

    // Sprawdza, czy liczba jest mniejsza
    if (liczba < korzen->liczba)
    {
        korzen->l = wstaw(korzen->l, liczba);
    }
    else
    {
        korzen->p = wstaw(korzen->p, liczba);
    }

    return korzen;
}

// Funkcja wypisuj¹ca drzewo
void wypisz(struct drzewo *korzen)
{
    if (korzen != NULL)
    {
        wypisz(korzen->l);
        printf("%d ", korzen->liczba);
        wypisz(korzen->p);
    }
}

int main()
{
    int liczba[] = {5, 2, 7, 6, 3};
    int n = 5;

    struct drzewo *korzen = NULL;

    // Pêtla dodaj¹ca liczby do drzewa
    for (int i = 0; i < n; i++)
    {
        korzen = wstaw(korzen, liczba[i]);
    }

    wypisz(korzen);

    return 0;
}
