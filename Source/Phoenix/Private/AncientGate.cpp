#include "AncientGate.h"

class AActor;
class UMaterialParameterCollection;
class UMaterialSwapComponent;
class USceneComponent;

void AAncientGate::SetAllCollisions(TArray<AActor*> i_RedTarget, TArray<AActor*> i_BlueTarget, TMap<AActor*, bool> i_PassThroughCheck, bool bIsRed) {
}

void AAncientGate::SetActorCollision(AActor* i_Actor, TEnumAsByte<ECollisionResponse> i_Response, TMap<AActor*, bool> i_PassThroughCheck) {
}

void AAncientGate::Rotating_Implementation() {
}

void AAncientGate::Recall_Implementation(AActor* Who, AActor* Pedestal) {
}

void AAncientGate::MaterialSetup(TArray<AActor*>& i_Target, TMap<UMaterialSwapComponent*, AActor*>& i_Materials, FLinearColor& i_Color) {
}

void AAncientGate::MaterialCutoutFlip(TMap<UMaterialSwapComponent*, AActor*> i_RedMaterials, TMap<UMaterialSwapComponent*, AActor*> i_BlueMaterials, UMaterialParameterCollection* i_Collection, bool bIsRedSide) {
}

void AAncientGate::InitialMaterialSetup(TArray<AActor*> i_RedTarget, TArray<AActor*> i_BlueTarget, TMap<UMaterialSwapComponent*, AActor*>& i_RedMaterials, TMap<UMaterialSwapComponent*, AActor*>& i_BlueMaterials, FLinearColor i_RedColor, FLinearColor i_BlueColor) {
}

void AAncientGate::AncientGateSetup(USceneComponent* i_ArrowComponent, USceneComponent* i_LeftPoint, USceneComponent* i_RightPoint, FLinearColor i_RedColor, FLinearColor i_BlueColor) {
}

AAncientGate::AAncientGate() {
    this->m_CurrentLeft = NULL;
    this->m_CurrentRight = NULL;
}

