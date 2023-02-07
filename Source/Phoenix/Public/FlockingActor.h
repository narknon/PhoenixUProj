#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "FlockCollisionParameters.h"
#include "FlockMemberInitialState.h"
#include "FlockPersonalities.h"
#include "FlockingParameters.h"
#include "FlockingParametersAdjustable.h"
#include "FlockingParametersAdjustableBlend.h"
#include "FlockingActor.generated.h"

class UMeshComponent;
class UParticleSystemComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class AFlockingActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Leader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockingParameters FlockingParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableCollisions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockCollisionParameters CollisionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableFlocking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlockingStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlockMemberInitialState> FlockInitialStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnablePersonalities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockPersonalities Personalities;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> FlockMemberMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> FlockMemberParticleSystems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFlockingParametersAdjustableBlend BlendFlockingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastLeaderPos;
    
public:
    AFlockingActor();
    UFUNCTION(BlueprintCallable)
    void SetFlockingStrength(float Strength);
    
    UFUNCTION(BlueprintCallable)
    void SetAdjustableParameters(FFlockingParametersAdjustable Parameters, float BlendTimeSeconds);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFlockingParametersAdjustable LerpFlockingParameters(FFlockingParametersAdjustable A, FFlockingParametersAdjustable B, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetAdjustableParameters(FFlockingParametersAdjustable& Parameters) const;
    
    UFUNCTION(BlueprintCallable)
    void Generate();
    
};

