/* Declara TAM_MAX */
const int TAM_MAX = 20001;

int representantes [TAM_MAX];
int intermedios[TAM_MAX];

int BuscarRepresentante(int amigo) {
    int numIntermedios = 0;

    while (representantes[amigo] != amigo) {
        amigo = representantes[amigo];
        intermedios[numIntermedios++] = amigo;
    }

    for (int i = 0; i < numIntermedios; i++) {
        representantes[intermedios[i]] = amigo;
    }

    return amigo;
}

void Unir (int rep1, int rep2) {
    if (rep1 != rep2) {
        representantes[rep2] = rep1;
        tamano[rep1] += tamano[rep2];
    }
}