/*
 * Objectif: Comprendre fork() et wait()
 * 
 * Créez un programme qui:
 * 1. Affiche "Parent: PID = ..."
 * 2. Crée un processus enfant avec fork()
 * 3. L'enfant affiche "Enfant: PID = ..." puis se termine
 * 4. Le parent attend la fin de l'enfant avec wait()
 * 5. Le parent affiche "L'enfant est terminé"
 */