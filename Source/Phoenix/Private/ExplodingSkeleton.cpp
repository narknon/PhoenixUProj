#include "ExplodingSkeleton.h"
#include "Templates/SubclassOf.h"

class AActor;
class AExplodingSkeleton;
class ASkinFXDefinition;
class UExplodingSkeletonPieceSetup;

AExplodingSkeleton* AExplodingSkeleton::SpawnExplodingSkeletonSkinFX(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, TSubclassOf<ASkinFXDefinition> SkinFXEffect, FName InCollisionProfileName, FVector BaseOffset) {
    return NULL;
}

AExplodingSkeleton* AExplodingSkeleton::SpawnExplodingSkeletonMIDFade(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName FadeMaterialParmeter, FName InCollisionProfileName, FVector BaseOffset) {
    return NULL;
}

AExplodingSkeleton* AExplodingSkeleton::SpawnExplodingSkeletonFade(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName FadeMaterialKey, FName FadeMaterialParmeter, FName InCollisionProfileName, FVector BaseOffset) {
    return NULL;
}

AExplodingSkeleton* AExplodingSkeleton::SpawnExplodingSkeleton_CollisionOverride(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName InCollisionProfileName, FVector BaseOffset) {
    return NULL;
}

AExplodingSkeleton* AExplodingSkeleton::SpawnExplodingSkeleton(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, bool bUseDitheredAlphaFade, FName InCollisionProfileName, FVector BaseOffset) {
    return NULL;
}

void AExplodingSkeleton::ExplodingSkeletonPieces(int32& TotalPieces, int32& CurrentlyAlivePieces) const {
}

AExplodingSkeleton::AExplodingSkeleton() {
    this->AlivePieces = 0;
    this->SkinFXComponent = NULL;
    this->MaterialSwap = NULL;
    this->Age = 0.00f;
    this->bDitheredAlphaFade = false;
}

