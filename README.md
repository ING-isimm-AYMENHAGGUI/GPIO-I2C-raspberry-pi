# GPIO-I2C-raspberry-pi
Dans ce projet j'ai utiliser les fichiers systèmes (sysfs) créés par Linux pour contrôler les GPIO. 
Ces fichiers spéciaux permettent d'utiliser le pilote système du media de communication.

La gestion des GPIO se trouvent dans le dossier /sys/class/gpio.
Dans ce dossier, on trouve 2 fichiers : export et unexport.
export donne accès au paramétrage et à la communication avec la broche choisie
du GPIO.
unexport permet de supprimer l'accès à la broche GPIO.
Il existe plusieurs manières de
considérer une broche du GPIO. Le
tableau ci-contre résume la situation.
Accéder aux pins du GPIO par lesystème de fichiers utilise la numérotation du composant électronique BCMXXXX.

**Réalisez les actions suivantes :**
1 - Choix de la broche GPIO4 :
  sudo echo "4" > /sys/class/gpio/export
  sudo chmod 777 /sys/class/gpio/gpio4

2 - Il faut ensuite définir la direction : in ou out.
  sudo echo "out" > /sys/class/gpio/gpio4/direction

3 - Il est maintenant possible de fixer la valeur de la sortie à 1 ou 0 :
  sudo echo "1" > /sys/class/gpio/gpio4/value

4 - Une fois terminé, il faut libérer la GPIO de la manière suivante :
  sudo echo "4" > /sys/class/gpio/unexport
