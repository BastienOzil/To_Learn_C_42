/*
 * Simulez un serveur de chat:
 * 
 * Structure Message:
 * - Timestamp (gettimeofday)
 * - ID du thread émetteur
 * - Contenu du message
 * 
 * Buffer circulaire de 50 messages partagé, protégé par mutex
 * 
 * 3 threads émetteurs:
 * - Envoient des messages toutes les 200-500ms (aléatoire)
 * - Format: "User%d: Message %d"
 * 
 * 1 thread afficheur:
 * - Affiche les nouveaux messages dès qu'ils arrivent
 * - Format: [HH:MM:SS.mmm] User2: Message 5
 * 
 * Le programme tourne 10 secondes puis s'arrête proprement
 */