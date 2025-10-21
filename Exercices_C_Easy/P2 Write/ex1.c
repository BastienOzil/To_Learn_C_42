/*
 * Créez un programme qui:
 * 1. Écrit "Message normal\n" sur stdout (fd 1)
 * 2. Écrit "Message d'erreur\n" sur stderr (fd 2)
 * 
 * Testez la différence:
 * - ./prog                    (les deux s'affichent)
 * - ./prog > output.txt       (seul stderr s'affiche à l'écran)
 * - ./prog 2> errors.txt      (seul stdout s'affiche à l'écran)
 * - ./prog > out.txt 2> err.txt (rien à l'écran, tout dans les fichiers)
 * 
 * N'utilisez PAS printf, uniquement write()!
 */