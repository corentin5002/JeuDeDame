# JeuDeDame

## Format msg envois

### Message type client:

ID(idClient)-SYS/GAME-...


- SYS  à propos de la connexion etc
	- connexion
	- deconnection
	- Action
		- Connexion
		- Authentification
		- creation compte
		- option game
			1. creation  J
			2. rejoindre J&Spec
			3. regarder  Spec
			4. quitter	J&Spec
- GAME à propos du jeu
 - Couple joué
 - Abandon (mais idem que *option Game : quitter*)

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
