# JeuDeDame

## Architecture des fichiers :

### Exécutables:
* client
* serveur
### Bibliothèques de fonctions:
* fctJdDame.c
	* fctJdDame.h
* fctReseau.c
	* fctReseau.h

Où client auras besoin des deux Bibliothèques et serveur que de celle de reseau
## Format msg envois

### Message type client:

ID(idClient)-SYS/GAME-...


- SYS  à propos de la connexion etc
	0. connexion serv ->
	1. déconnexion
	2. Action
 		0. Authentification
			0. compte existant 	idClient-SYS-200-*pseudo*
			1. nv compte 		idClient-SYS-201-*pseudo*
			2. invite 			idClient-SYS-202
		1. creation compte
		2. option game
			0. creation  J 	   	idClient-SYS-220-information-username -> idGame
			1. rejoindre J  	idClient-SYS-2210 -> liste partie -> ...-2211 -> idGame
			2. regarder  Spec   
			3. quitter	J&Spec	idClient
- GAME à propos du jeu
 - Couple joué
 - Abandon (mais idem que *option Game : quitter*)

si soucis serv ou client renvoie "errorMsg"

envoi()-> reception() -> gareTriageServ -> envoi()

### Message type serveur

client(idClient)-SYS


12080-SYS-22
```c
while(c != '\0')
{
	i++;
	c = str[i];
	if (strcmp('c',c) == 0)
	{

	}
}
```















## Idée fonction `exploreCheminEnnemie()`

Cette fonction ne serait plus destinée à retourner TOUT le chemin, mais seulement les case atterrissages qui sont dans les chemins les plus longs.

type de retour : int * [n,cAV1,cAV2,...,cAV4]

où n est la longueur du chemin et cAVi le numéro de case d'atterrissage voisin i.

On l'utiliserait en remontant le chemin, case d'atterrissage par case d'atterrissage.

et à chaque fois on devrait juste demander si la case est valide pour le joueur au serveur.

# Note pour git

*Tes meilleurs amis*

- `git status`
- `git checkout <nomBranch>`
- `git push` (et s'est dérivés)
- `git branch`
- `git merge / rebase`


se connecter au dépôt :
```bash
git init

git remote add origin git@github.com:corentin5002/JeuDeDame.git
git branch -M main
git push -u origin main

or

echo "# JeuDeDame" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:corentin5002/JeuDeDame.git
git push -u origin main
```
