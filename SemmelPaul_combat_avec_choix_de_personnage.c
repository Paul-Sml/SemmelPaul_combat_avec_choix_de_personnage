#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>


int genRandoms(int lower, int upper,int count){ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return num; 
    } 
} 

int genRandoms2(int lower2, int upper2,int count){ 
    int i2; 
    for (i2 = 0; i2 < count; i2++) { 
        int num2 = (rand() % 
           (upper2 - lower2 + 1)) + lower2; 
        return num2; 
    } 
} 

void clrscr(){
    system("@cls||clear");
}


//-------------------------------------TOUR DU JOUEUR----------------------------------------------------------
int tourPlayer(int pvMonstre,int pvJoueur,int pmJoueur,int classe,int amuletteMagique, int choixClasse){
	int choix;
	
	printf("Que voulez vous faire ? \nAttaque:1 Defense:2 Competence:3 Antidote:4 Changer de personnage:5\n");
	scanf("%d",&choix);
	if (choix == 1)
	{
		return choix;
	}
	if (choix == 2)
	{
		return choix;
	}
	if (choix == 3)
	{
		if ((classe == 1 && pmJoueur>=20) || (classe == 2 && pmJoueur>=20) || (classe==3 && pmJoueur>=15-amuletteMagique) || (classe==4 && pmJoueur>=10))
		{
			return choix;	

		}
		else{
			clrscr();
			printf("vous n'avez pas assez de PM !\n");
			tourPlayer(pvMonstre,pvJoueur,pmJoueur,classe,amuletteMagique,choixClasse);
		}
	}
	if (choix == 4)
	{
		return choix;
	}
	if (choix == 5){
		printf("Quel personnage souhaitez vous envoyer au combat ?\nPaladin : 1\nSorcier : 2\nVoleur : 3\nRanger : 4\n");
		scanf("\n%d",choixClasse);
		clrscr();
		if (choixClasse==classe){
			printf("Il est déjà au combat\n");
			tourPlayer(pvMonstre,pvJoueur,pmJoueur,classe,amuletteMagique,choixClasse);
			}else{
				classe = choixClasse;
			}
		}
}

//-------------------------------------TOUR DU MONSTRE----------------------------------------------------------
int tourMonstre(int pvMonstre,int pvJoueur,int lower, int upper,int count){
	int choix;
	printf("Tour du monstre!\n");
	choix = genRandoms(lower, upper, count);
	return choix;

}

int poison(){
}


//-------------------------------------FONCTION MAIN------------------------------------------------------
int main(int pvJoueur,int pvMonstre, int pmJoueur)
{
//-------------------------------------VARIABLES----------------------------------------------------------

	int classe;
	int choixClasse;
	int choix;
	int lower = 1, upper = 3, count = 1;
	int lower2 = 1, upper2 = 7;
	int game = 1;
	int defOn = 0;
	int tour;
	int tourM;
	pvMonstre = 50; 
	int pvPaladin = 80;
	int pvSocier = 40;
	int pvVoleur = 50;
	int pvRanger = 60;
	pmJoueur;
	int pmJoueurMax;
	int pvJoueurMax;
	int defOnM = 0;
	int bleedL = 0;
	srand(time(0));
	int nombreDeMonstres = 1;
	int furtiv = 1;
	int itemShop1r;
	int itemShop2r;
	int itemShop3r;
	char itemShop1[122];
	char itemShop2[122];
	char itemShop3[122];
	int steroides = 0;
	int amuletteMagique = 0;
	int anneauDeSante = 0;
	int anneauDeMana = 0;
	int choixItem;

//---------------------------------CHOIX DE LA CLASSE-----------------------------------------------------
classe = 1;
//------------------------------BOUCLE DE JEU-------------------------------------------------------------
	while(pvJoueur>0){
		pvMonstre = nombreDeMonstres*10;
		while(pvPaladin>0 && pvSocier>0 && pvVoleur>0 && pvRanger>0 && pvMonstre>0){
			defOn = 0;
			pmJoueur+=2+anneauDeMana;
			if (pmJoueur>pmJoueurMax) {pmJoueur=pmJoueurMax;}
			tour = tourPlayer(pvMonstre, pvJoueur, pmJoueur,classe,amuletteMagique,choixClasse);
			printf("%d\n",bleedL);

//-------------------------------------ATTAQUE------------------------------------------------------------
			if (tour == 1)
			{
				if (defOnM == 1)
				{
					clrscr();
					printf("Vous attaquez le monstre mais il se defend\n");
					
				}
				else{
					clrscr();
					pvMonstre -= 8+(4*steroides);
					printf("Vous attaquez le monstre, il lui reste %dPV\n",pvMonstre );	
					
				}				
			}

//-------------------------------------DEFENSE------------------------------------------------------------
			if (tour == 2)
			{
				clrscr();
				defOn = 1;
				printf("Vous vous defendez ! Vous bloquerez les degats si le monstre vous attaque.\n");
				
			}
//--------------------------------------SORT--------------------------------------------------------------
			if (tour == 3)
			{
				//---PALADIN---
				if (classe == 1){
					clrscr();
					pmJoueur  -= 20;
					pvMonstre -= 0;
					pvJoueur  += 30+(15*amuletteMagique);
					if (pvJoueur>pvJoueurMax){
						pvJoueur = pvJoueurMax;
					printf("Vous lancez Lumiere divine ! \nVous perdez 20PM ! il vous reste %d PM\nVous avez recupere tous vos PV\n",pmJoueur);
					}
					else{	
						printf("Vous lancez Lumiere divine ! \nVous perdez 20PM ! il vous reste %d PM\nil vous reste %d PV\n",pmJoueur,pvJoueur);
					}		
				}

				//---SORCIER---
				if (classe == 2){
					clrscr();
					pmJoueur -=20;
					pvMonstre -= 26+(13*amuletteMagique);
					printf("Vous lancez une boule de feu ! \n Vous perdez 20PM ! il vous reste %d PM\n Elle inflige 25 points de degats au Monstre !\n il lui reste %d PV\n",pmJoueur,pvMonstre);
				}



				//---VOLEUR---
				if (classe == 3){
					clrscr();
					if (amuletteMagique<15)
					{
						pmJoueur -=15-amuletteMagique;
					}else
					printf("Vous lancez Furtivite ! \n Il vous reste %d PM\n Vous esquiverez la prochaine attaque.\n",pmJoueur,pvJoueur);
					furtiv = 1;
				}


				//---RANGER---
				if (classe == 4){
					clrscr();
					pmJoueur -=10;
					pvMonstre -= 12;
					printf("Vous tirez la flèche de feu ! \n Vous perdez 10PM ! il vous reste %d PM\n Elle inflige 12 points de degats au Monstre !\n il lui reste %d PV\n",pmJoueur,pvMonstre);
				}
			}
	
//------------------------------------ANTIDOTE------------------------------------------------------------
			if (tour == 4)
			{
				clrscr();
				bleedL = 0;
				printf("Vous prenez le temps de vous soigner, vous n'etes plus empoisonne!\n" );
			}

//--------------------------------TOUR DU MONSTRE---------------------------------------------------------
			printf("\n");
			defOnM = 0;
			if (pvMonstre>0)
			{
				tourM = tourMonstre(pvMonstre, pvJoueur,lower, upper, count);
				if (tourM == 1){
					
					if (furtiv == 1){
						furtiv=0;
						}
					else{	
						if (defOn == 1)
					{
						printf("Le monstre vous attaque ! grace a votre defense vous ne aucun PV\n",pvJoueur);
					}else{
						pvJoueur-=2*nombreDeMonstres;
						printf("Le monstre vous attaque !\nIl vous reste %dPV\n",pvJoueur);
						}
					}
					
				}
				if (tourM == 2)
				{
					defOnM = 1;
					printf("Le monstre se defend ! Il bloquera les degats si vous attaquez.\n");
				}
				if (tourM == 3)
				{
					bleedL++;
					printf("Le monstre vous empoisonne ! Vous devez vous guerir ou vous perdrez %d par tour !\n",bleedL );
				}
				printf("\n");

			}
				
		}
		if (pvMonstre<=0){
			nombreDeMonstres++;
				pvJoueur += 20+(10*anneauDeSante);
				if (pvJoueur>pvJoueurMax){pvJoueur = pvJoueurMax;}
				printf("Vous vous soignez, vous avez %d PV\n",pvJoueur);
			//------------------------------------SHOP----------------------------------------------------
				itemShop1r = genRandoms2(lower2, upper2, count);
				itemShop2r = genRandoms2(lower2, upper2, count);
				itemShop3r = genRandoms2(lower2, upper2, count);
				if(itemShop1r==1){strcpy(itemShop1, "Steroides (ameliore l'attaque de 4)");}
				if(itemShop1r==2){strcpy(itemShop1, "Amulette magique (Paladin : ameliore le soin | Sorcier : ameliore la boule de feu | Voleur : reduit le cout de furtivite)");}
				if(itemShop1r==3){strcpy(itemShop1, "Anneau de sante (ameliore la regeneration apres un combat)");}
				if(itemShop1r==4){strcpy(itemShop1, "Anneau de mana (ameliore la regeneration de PM pendant un combat)");}
				if(itemShop1r==5){strcpy(itemShop1, "Armure (augmente vos PV max)");}
				if(itemShop1r==6){strcpy(itemShop1, "Soudoyer le vendeur (vous n'aurez plus jamais de choix vide lors de la rencontre avec le vendeur)");}
				if(itemShop1r==7){strcpy(itemShop1, "Vide");}

				if(itemShop2r==1){strcpy(itemShop2, "Steroides (ameliore l'attaque de 4)");}
				if(itemShop2r==2){strcpy(itemShop2, "Amulette magique (Paladin : ameliore le soin | Sorcier : ameliore la boule de feu | Voleur : reduit le cout de furtivite)");}
				if(itemShop2r==3){strcpy(itemShop2, "Anneau de sante (ameliore la regeneration apres un combat)");}
				if(itemShop2r==4){strcpy(itemShop2, "Anneau de mana (ameliore la regeneration de PM pendant un combat)");}
				if(itemShop2r==5){strcpy(itemShop2, "Armure (augmente vos PV max)");}
				if(itemShop2r==6){strcpy(itemShop2, "Soudoyer le vendeur (vous n'aurez plus jamais de choix vide lors de la rencontre avec le vendeur)");}
				if(itemShop2r==7){strcpy(itemShop2, "Vide");}

				if(itemShop3r==1){strcpy(itemShop3, "Steroides (ameliore l'attaque de 4)");}
				if(itemShop3r==2){strcpy(itemShop3, "Amulette magique (Paladin : ameliore le soin | Sorcier : ameliore la boule de feu | Voleur : reduit le cout de furtivite)");}
				if(itemShop3r==3){strcpy(itemShop3, "Anneau de sante (ameliore la regeneration apres un combat)");}
				if(itemShop3r==4){strcpy(itemShop3, "Anneau de mana (ameliore la regeneration de PM pendant un combat)");}
				if(itemShop3r==5){strcpy(itemShop3, "Armure (augmente vos PV max)");}
				if(itemShop3r==6){strcpy(itemShop3, "Soudoyer le vendeur (vous n'aurez plus jamais de choix vide lors de la rencontre avec le vendeur)");}
				if(itemShop3r==7){strcpy(itemShop3, "Vide");}

				printf("Quel objet voulez vous ?\n1) %s\n2) %s\n3) %s\n",itemShop1,itemShop2,itemShop3);
				scanf("%d",&choixItem);
				if (choixItem == 1)
				{
					if(itemShop1r==1){steroides++;}
					if(itemShop1r==2){amuletteMagique++;}
					if(itemShop1r==3){anneauDeSante++;}
					if(itemShop1r==4){anneauDeMana++;}
					if(itemShop1r==5){pvJoueurMax+=30;pvJoueur+=30;}
					if(itemShop1r==6){upper2=5;}
				}
				if (choixItem == 2)
				{
					if(itemShop2r==1){steroides++;}
					if(itemShop2r==2){amuletteMagique++;}
					if(itemShop2r==3){anneauDeSante++;}
					if(itemShop2r==4){anneauDeMana++;}
					if(itemShop2r==5){pvJoueurMax+=30;pvJoueur+=30;}
					if(itemShop2r==6){upper2=5;}
				}
				if (choixItem == 3)
				{
					if(itemShop3r==1){steroides++;}
					if(itemShop3r==2){amuletteMagique++;}
					if(itemShop3r==3){anneauDeSante++;}
					if(itemShop3r==4){anneauDeMana++;}
					if(itemShop3r==5){pvJoueurMax+=30;pvJoueur+=30;}
					if(itemShop3r==6){upper2=5;}
				}
				clrscr();
		}
		else{
			printf("Le monstre reussi a vous achever...\nVous avez atteint le %de monstre", nombreDeMonstres);
		}
	}	
	return 0;
	}