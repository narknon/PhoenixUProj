#include "Enemy_TombProtector_QBUpdateDataAsset.h"

UEnemy_TombProtector_QBUpdateDataAsset::UEnemy_TombProtector_QBUpdateDataAsset() {
    this->bSpawnMeteors = true;
    this->ScaleMin = 0.50f;
    this->ScaleMax = 2.00f;
    this->NumMeteorsToSpawn = 25;
    this->OrbitRotationMin = 10.00f;
    this->OrbitRotationMax = 50.00f;
    this->NumPiecesMin = 7;
    this->NumPiecesMax = 10;
    this->PiecesSpawnOffsetMin = 100.00f;
    this->PiecesSpawnOffsetMax = 300.00f;
    this->PiecesScaleMin = 0.50f;
    this->PiecesScaleMax = 1.00f;
    this->BreakApartSpeedMin = 50.00f;
    this->BreakApartSpeedMax = 100.00f;
    this->MinAccuracy = 0.00f;
    this->MaxAccuracy = 500.00f;
}

