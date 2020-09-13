
void readfile(){
  FILE* f;
  if((f = fopen("fichero.txt", "rb"))==NULL){
    fprintf(stderr, "\nNo se pudo abrir %s", "fichero.txt");
    exit(-1);
  }
  else{
    


  }
}
