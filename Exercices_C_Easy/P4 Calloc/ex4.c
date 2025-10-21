/*
 * Créez un buffer circulaire pour stocker les N dernières valeurs:
 * 
 * typedef struct {
 *     int *data;
 *     int size;
 *     int head;
 *     int count;
 * } CircularBuffer;
 * 
 * CircularBuffer *cb_create(int size);
 * void cb_push(CircularBuffer *cb, int value);
 * void cb_print(CircularBuffer *cb);
 * void cb_free(CircularBuffer *cb);
 * 
 * Testez en ajoutant 15 valeurs dans un buffer de taille 10
 * Seules les 10 dernières doivent être conservées
 */