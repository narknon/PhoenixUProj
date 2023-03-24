#include "GlaciusSpellTool.h"

AGlaciusSpellTool::AGlaciusSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TerrainImpactZOffset = 0.00f;
    this->GlaciusTerrainImpactComponent = NULL;
    this->GlaciusPlatformClass = NULL;
    this->PlatformMax = 2;
    this->PlatformLifetime = 5.00f;
    this->PlatformScale = 1.00f;
    this->PlatformScaleTime = 1.00f;
    this->AOEMunition = NULL;
}

