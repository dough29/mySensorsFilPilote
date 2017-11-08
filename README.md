# mySensorsFilPilote
Sketch MySensors pour la gestion du fil pilote (4 ordres - off/hors gel/éco/confort)

Basé sur les travaux publiés ici : http://telefab.fr/2013/11/10/controle-a-distance-des-radiateurs/

## BOM :

* 1 x Arduino Pro Mini 3.3v
* 2 x MOC3041
* 1 x nRF24l01
* 2 x diode 1N4007
* 2 x résistance 470ohms

## Configuration de l'équipement sous Jeedom (plugin MySensors) :
- la commande d'information "État" se crée automatiquement : type "info" - id capteur "1" - type capteur "23 - Custom" - type donnée "21 - Mode chauffage"
- créer la commande d'action "Off" : type "action" - id capteur "1" - type capteur "1 - Paramétrage" - valeur "O" - type donnée "21 - Mode chauffage"
- créer la commande d'action "Hors gel" : type "action" - id capteur "1" - type capteur "1 - Paramétrage" - valeur "G" - type donnée "21 - Mode chauffage"
- créer la commande d'action "Eco" : type "action" - id capteur "1" - type capteur "1 - Paramétrage" - valeur "E" - type donnée "21 - Mode chauffage"
- créer la commande d'action "Confort" : type "action" - id capteur "1" - type capteur "1 - Paramétrage" - valeur "C" - type donnée "21 - Mode chauffage"

Sujet sur le Forum Jeedom : https://www.jeedom.com/forum/viewtopic.php?f=35&t=22499
