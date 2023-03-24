#include "GlaciusMaximaSpellTool.h"

AGlaciusMaximaSpellTool::AGlaciusMaximaSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GlaciusActorClass = NULL;
    this->GlaciusImpactComponent = NULL;
    this->GlaciusTerrainImpactComponent = NULL;
    this->GlaciusPlatformClass = NULL;
    this->SkinFX = NULL;
    this->TerrainImpactZOffset = 0.00f;
}

