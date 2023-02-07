#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ExplodingSkeletonDoneEventDelegateDelegate.h"
#include "ExplodingSkeletonImpulse.h"
#include "ExplodingSkeletonInitialDelay.h"
#include "ExplodingSkeletonPieceTracker.h"
#include "Templates/SubclassOf.h"
#include "ExplodingSkeleton.generated.h"

class AExplodingSkeleton;
class ASkinFXDefinition;
class UExplodingSkeletonPieceSetup;
class UMaterialSwapMeshPool;
class USkinFXComponent;

UCLASS(Blueprintable, Transient)
class AExplodingSkeleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FExplodingSkeletonDoneEventDelegate ExplodingSkeletonDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FExplodingSkeletonPieceTracker> Pieces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AlivePieces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkinFXComponent* SkinFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ObjectFadeMaterialParmeter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwapMeshPool* MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FExplodingSkeletonImpulse Impulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDitheredAlphaFade;
    
    AExplodingSkeleton();
    UFUNCTION(BlueprintCallable)
    static AExplodingSkeleton* SpawnExplodingSkeletonSkinFX(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, TSubclassOf<ASkinFXDefinition> SkinFXEffect, FName InCollisionProfileName, FVector BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static AExplodingSkeleton* SpawnExplodingSkeletonMIDFade(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName FadeMaterialParmeter, FName InCollisionProfileName, FVector BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static AExplodingSkeleton* SpawnExplodingSkeletonFade(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName FadeMaterialKey, FName FadeMaterialParmeter, FName InCollisionProfileName, FVector BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static AExplodingSkeleton* SpawnExplodingSkeleton_CollisionOverride(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, FName InCollisionProfileName, FVector BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static AExplodingSkeleton* SpawnExplodingSkeleton(AActor* SourceActor, UExplodingSkeletonPieceSetup* PieceSetup, FExplodingSkeletonImpulse InitialImpulse, FExplodingSkeletonInitialDelay InitialDelay, bool bUseDitheredAlphaFade, FName InCollisionProfileName, FVector BaseOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void ExplodingSkeletonPieces(int32& TotalPieces, int32& CurrentlyAlivePieces) const;
    
};

