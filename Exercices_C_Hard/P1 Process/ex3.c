/*
 * Créez un programme où:
 * 1. Le parent installe un handler pour SIGUSR1
 * 2. Le parent crée un enfant
 * 3. L'enfant envoie SIGUSR1 au parent avec kill()
 * 4. Le handler du parent affiche "Signal reçu!"
 */