/*
 * Améliorez le shell pour accepter des arguments:
 * - Parsez la ligne: "ls -l -a"
 * - Créez le tableau argv: ["ls", "-l", "-a", NULL]
 * - Cherchez le programme dans PATH avec getenv("PATH")
 * - Exécutez avec execve()
 */