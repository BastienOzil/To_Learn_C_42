/*
 * Simulez: ls -l | grep ".c"
 * 
 * 1. Créez un pipe
 * 2. Fork pour ls: redirige stdout vers le pipe, execve "ls"
 * 3. Fork pour grep: redirige stdin depuis le pipe, execve "grep"
 * 4. Le parent attend les deux enfants
 */