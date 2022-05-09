#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int * lista;
    int last;
    int max;
} Vetor;

void create_vetor(Vetor * vetor, int max) {
    int * lista = malloc(max * sizeof(int));
    int last = 0; 
    
    vetor->lista = lista;
    vetor->last = last;
    vetor->max = max;
}

int insert(Vetor * vetor, int pos, int element) {
    if (pos >= vetor->max) {
        return 0; 
    } else {
        if (pos == vetor->last) {
            vetor->lista[vetor->last] = element; 
            vetor->last++; 
            return 1; 
        } else {
            int i;
            for (i = vetor->last; i > pos; i--) {
                vetor->lista[i] = vetor->lista[i-1];
            }
            vetor->lista[pos] = element;
            vetor->last++;
            return 1;
        }
    }
}

int delete(Vetor * vetor, int pos) {
    if (pos >= vetor->last) {
        return 0; 
    } else {
        if (pos == vetor->last) {
            vetor->last--;
            return 1;
        } else {
            int i;
            for (i = pos; i < vetor->last; i++) {
                vetor->lista[i] = vetor->lista[i+1];
            }
            vetor->last--;
        }
    }
}

int locate(Vetor * vetor, int element) {
    int i; 
    int local = -1; 
    for (i = 0; i <= vetor->last; i++) {
        if (vetor->lista[i] == element) {
            local = i;
            break; 
        }
    }
    return local; 
}



int main() {
    Vetor vetor;

    create_vetor(&vetor, 100);
    insert(&vetor, 0, 12);
    insert(&vetor, 1, 13);
    insert(&vetor, 2, 14);
    insert(&vetor, 0, 15);

    delete(&vetor, 1);


    int i; 
    for (i = 0; i < vetor.last; i++) {
        printf("%d ", vetor.lista[i]);
    }

    printf("\n%d", locate(&vetor, 14));


    return 0; 
}