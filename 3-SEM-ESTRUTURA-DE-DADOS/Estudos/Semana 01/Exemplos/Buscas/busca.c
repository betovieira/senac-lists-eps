int busca_linear(int *v, int n, int q) {
  int i;

  for(i = 0; i < n; i++)
    if(v[i] == q)
      return i;

  return -1;
}


int busca_binaria_1(int *v, int n, int q) {
  int esq = 0, dir = n - 1;

  while(esq <= dir) {
    int meio = (esq + dir) / 2;

    if(v[meio] == q)
      return meio;

    if(v[meio] < q)
      esq = meio + 1;
    else
      dir = meio - 1;
  }

  return -1;
}


int busca_binaria_r(int *v, int esq, int dir, int q) {
  if(esq > dir)
    return -1;

  int meio = (esq + dir) / 2;

  if(v[meio] == q)
    return meio;

  if(v[meio] < q)
    return busca_binaria_r(v, meio + 1, dir, q);
  else
    return busca_binaria_r(v, esq, meio - 1, q);
}


int busca_binaria_2(int *v, int n, int q) {
  return busca_binaria_r(v, 0, n - 1, q);
}
