//Creación de hilos consumidores
for (i = 0; i < NCONSUM; i++) {
  v[i] = i;
  if ((status = pthread_create(&consumidores[i], NULL, consumiendo, NULL)))
    exit(status);
}


//Recogida de hilos consumidores
for (i = 0; i < NCONSUM; i++) {
    pthread_join(consumidores[i], (void **) &r_value);
    printf("Valor devuelto por el hilo %lu : %lf\n", consumidores[i], *r_value);
}
