#include <MySensor.h>

#define MOC_P 3 // MOC phase positive
#define MOC_N 4 // MOC phase négative

#define CHILD_ID_FP 1 // Identifiant du capteur

MySensor gw;

typedef struct {
   char mode_code;
   int code_p;
   int code_n;
} modeFilPilote;

modeFilPilote modesFilPilote[4] = {
  {'O', 1, 0}, // Mode Off
  {'G', 0, 1}, // Mode hors gel
  {'E', 1, 1}, // Mode éco
  {'C', 0, 0}  // Mode confort
};

void setup() {
  gw.begin(incomingMessage, AUTO, true);
  gw.sendSketchInfo("Fil pilote", "1.0");
  gw.present(CHILD_ID_FP, S_CUSTOM);

  pinMode(MOC_P, OUTPUT);
  pinMode(MOC_N, OUTPUT);

  // Restauration du mode sauvegardé
  digitalWrite(MOC_P, gw.loadState(MOC_P));
  digitalWrite(MOC_N, gw.loadState(MOC_N));
}

void loop() {
  gw.process();
}

void incomingMessage(const MyMessage &message) {
  if (message.type == V_HVAC_FLOW_STATE) {
    for(int i=0; i < 4; i++) {
      if(message.getString()[0] == modesFilPilote[i].mode_code) {
        digitalWrite(MOC_P, modesFilPilote[i].code_p);
        digitalWrite(MOC_N, modesFilPilote[i].code_n);
        
        // Sauvegarde du mode
        gw.saveState(MOC_P, modesFilPilote[i].code_p);
        gw.saveState(MOC_N, modesFilPilote[i].code_n);
        return;
      }
    }
  }
}

