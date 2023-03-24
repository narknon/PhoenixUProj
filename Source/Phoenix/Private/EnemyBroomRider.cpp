#include "EnemyBroomRider.h"

class AActor;

FName AEnemyBroomRider::OnOverrideCharacterLook_Implementation(AActor* Actor, FName Name) {
    return NAME_None;
}

AEnemyBroomRider::AEnemyBroomRider(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

