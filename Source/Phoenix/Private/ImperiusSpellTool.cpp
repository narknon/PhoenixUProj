#include "ImperiusSpellTool.h"

class UStateEffectComponent;

void AImperiusSpellTool::DoSpellComponentSetup(UStateEffectComponent* StateEffectComponent) {
}

AImperiusSpellTool::AImperiusSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mod = NULL;
}

