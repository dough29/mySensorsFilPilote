#include <MySensor.h>

#define MOC_P 3 // MOC branché sur la phase
#define MOC_N 4 // MOC branché sur le neutre

#define CHILD_ID_FP 1 // Identifiant du capteur

MySensor gw;

void setup() {
  gw.begin(incomingMessage, AUTO, true);
  gw.sendSketchInfo("Fil pilote", "1.0");
  gw.present(CHILD_ID_FP, S_CUSTOM);

  pinMode(MOC_P, OUTPUT);
  pinMode(MOC_N, OUTPUT);

  switch (gw.loadState(CHILD_ID_FP)) {
    case 'O': // Off
      digitalWrite(MOC_P, 1);
      digitalWrite(MOC_N, 0);
      break;
    case 'G': // Hors gel
      digitalWrite(MOC_P, 0);
      digitalWrite(MOC_N, 1);
      break;
    case 'E': // Eco
      digitalWrite(MOC_P, 1);
      digitalWrite(MOC_N, 1);
      break;
    case 'C': // Confort
      digitalWrite(MOC_P, 0);
      digitalWrite(MOC_N, 0);
      break;
  }
}

void loop() {
  gw.process();
}

void incomingMessage(const MyMessage &message) {
  if (message.type == V_HVAC_FLOW_STATE) {
    switch (message.getString()[0]) {
      case 'O': // Off
        digitalWrite(MOC_P, 1);
        digitalWrite(MOC_N, 0);
        break;
      case 'G': // Hors gel
        digitalWrite(MOC_P, 0);
        digitalWrite(MOC_N, 1);
        break;
      case 'E': // Eco
        digitalWrite(MOC_P, 1);
        digitalWrite(MOC_N, 1);
        break;
      case 'C': // Confort
        digitalWrite(MOC_P, 0);
        digitalWrite(MOC_N, 0);
        break;
    }
    gw.saveState(CHILD_ID_FP, message.getString()[0]);
  }
}

