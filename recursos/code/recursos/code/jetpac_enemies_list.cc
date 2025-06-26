

#define TNode TEnemyNode

bool EmptyList(TNode *list){
    return (list==nullptr);
}

void CreateList(TNode **list){
  *list=nullptr;
}

void InsertEnemy(TNode **node, TEnemy enemy){
  TNode *aux;
  aux=(TNode*)malloc((1)*sizeof(TNode));
  aux->enemy=enemy;
  aux->next= *node;
  *node = aux;
  g_num_enemies++;
}

TNode *SearchInEnemiesList(TNode *list,int data_type=0, int depth=0,
                            float x=NULL, float y=NULL){
  TNode *p;
  bool found=false;
  if(!EmptyList(list)){
    p=list;
    switch (depth) {
      case 0: data_type=data_type;
      case 1: data_type*=10;
    }
    while(!found && p!=nullptr) {
      switch(data_type){
        case  3: found=(!p->enemy.alive);break;
        case  2: found=(p->enemy.pos.x==x)&&(p->enemy.pos.y==x);break;
        case  1: found=(p->enemy.pos.x==x)||(p->enemy.pos.y==x);break;
    	  case 10: found=(p->next->enemy.pos.x==x)||
                      (p->next->enemy.pos.y==y);break;
        case 20: found=(p->next->enemy.pos.x==x)&&
                      (p->next->enemy.pos.y==y);break;
        case 30: if(p->next!=nullptr) {
          found=(!p->next->enemy.alive);break;
        }
    	}
      if(!found) {
        p=p->next;
      }
    }
  }
  return p;
}

void DeleteDeathEnemiesFromList(TNode **list) {
	TNode *p,*q;
	if(!EmptyList(*list)) {
    p=*list;
		 if(!p->enemy.alive) {
		 	*list=p->next;
		 	free(p);
      g_num_enemies--;
    } else if (p->enemy.alive) {
		 	p=SearchInEnemiesList(*list,3,1);
      if(p!=nullptr) {
        q=p->next;
		 		p->next=q->next;
		 		free(q);
        g_num_enemies--;
		  }
    }
	}
}

void SetAllEnemiesDead(TNode **list) {
  for(TNode *del=*list; del!=nullptr; del=del->next) {
    del->enemy.alive=false;
  }
}

void MuestraLista(TNode *r){
  TNode *p=nullptr;
  for(p=r;p!=nullptr;p=p->next){
    printf("%f,\t",p->enemy.pos.x);
    printf("%f,\t",p->enemy.pos.y);
    printf("%d,\t",p->enemy.type);
    printf("%d\t",p->enemy.points);
    printf("%d\t",p->enemy.hori);
    printf("%d\t",p->enemy.vert);
    printf("%d\n",p->enemy.alive);
  }
  printf("\n");
}
