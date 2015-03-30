void rotaciona_esq(arvore *a, no *n) {
  no *m = n->dir;

  n->dir = m->esq;

  if(m->esq != NULL)
    m->esq->pai = n;

  m->pai = n->pai;

  if(n->pai == NULL)
    a->raiz = m;
  else
    if(n->pai->esq == n)
      n->pai->esq = m;
    else
      n->pai->dir = m;

  m->esq = n;

  n->pai = m;
}


void rotaciona_dir(arvore *a, no *m) {
  no *n = m->esq;

  m->esq = n->dir;

  if(n->dir != NULL)
    n->dir->pai = m;

  n->pai = m->pai;

  if(m->pai == NULL)
    a->raiz = n;
  else
    if(m->pai->esq == m)
      m->pai->esq = n;
    else
      m->pai->dir = n;

  n->dir = m;

  m->pai = n;
}