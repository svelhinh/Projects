echo "\033[93m1 ligne vide a la fin :\033[92m"
./../fillit errors/e_1ligne_vide_a_la_fin
echo "\n\033[93m1 ligne vide au debut :\033[92m"
./../fillit errors/e_1ligne_vide_au_debut
echo "\n\033[93m2 lignes vides :\033[92m"
./../fillit errors/e_2lignes_vides
echo "\n\033[93mPas de \\\n a la fin :\033[92m"
./../fillit errors/e_serpent
echo "\n\033[93mAutres characteres :\033[92m"
./../fillit errors/e_autres_chars
./../fillit errors/e_autres_chars2
echo "\n\033[93m2 tetriminos ensemble :\033[92m"
./../fillit errors/e_blk_fusion
echo "\n\033[93mPas assez de blocs :\033[92m"
./../fillit errors/e_blkm
./../fillit errors/e_blkm2
echo "\n\033[93mTrop de blocs :\033[92m"
./../fillit errors/e_blkp
./../fillit errors/e_blkp2
echo "\n\033[93mLigne trop courte :\033[92m"
./../fillit errors/e_nbcharm
./../fillit errors/e_nbcharm2
echo "\n\033[93mLigne trop longue :\033[92m"
./../fillit errors/e_nbcharp
./../fillit errors/e_nbcharp2
echo "\n\033[93mPas assez de lignes :\033[92m"
./../fillit errors/e_nblignesm
./../fillit errors/e_nblignesm2
echo "\n\033[93mTrop de lignes :\033[92m"
./../fillit errors/e_nblignesp
./../fillit errors/e_nblignesp2
echo "\n\033[93mTetriminos invalides :\033[92m"
./../fillit errors/e_notetri
./../fillit errors/e_notetri2
./../fillit errors/e_notetri3
./../fillit errors/e_notetri4
./../fillit errors/e_notetri5
./../fillit errors/e_notetri6
./../fillit errors/e_notetri7
./../fillit errors/e_notetri8
./../fillit errors/e_notetri9
./../fillit errors/e_notetri10
./../fillit errors/e_notetri11
./../fillit errors/e_notetri12
./../fillit errors/e_notetri13
echo "\n\033[93m2 parametres :\033[92m"
./../fillit tests/errors/e_blkm tests/errors/e_blkm
echo "\n\033[93mAucun parametre :\033[92m"
./../fillit
echo "\n\033[93mFichier non existant :\033[92m"
./../fillit ksfkzshgfkj
echo "\n\033[93mFichier vide :\033[92m"
./../fillit errors/e_fichier_vide
echo "\n\033[93mFichier vraiment vide :\033[92m"
./../fillit errors/e_fichier_vide_noendl
echo "\n\033[93m1 seule ligne avec des points :\033[92m"
./../fillit errors/e_1_seule_ligne
echo "\n\033[93mSerpent :\033[92m"
./../fillit errors/e_serpent
echo "\n\033[93mTest algo :\n\033[92m"
./../fillit fonctionnel_sujet
echo "\n\033[93m1 :\n\033[92m"
./PcsGen.py 1 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m5 :\n\033[92m"
./PcsGen.py 5 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m7 :\n\033[92m"
./PcsGen.py 7 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m9 :\n\033[92m"
./PcsGen.py 9 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m13 :\n\033[92m"
./PcsGen.py 13 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m17 :\n\033[92m"
./PcsGen.py 17 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m21 :\n\033[92m"
./PcsGen.py 21 > yo
time ./../fillit yo
rm yo
echo "\n"
