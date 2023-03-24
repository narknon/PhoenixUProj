#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "FlockCollisionParameters.h"
#include "FlockGenerationParameters.h"
#include "FlockMemberInitialConditions.h"
#include "FlockMemberInitialState.h"
#include "FlockPersonalities.h"
#include "FlockingFadeParameters.h"
#include "FlockingParameters.h"
#include "FlockingParametersAdjustable.h"
#include "FlockingParametersAdjustableBlend.h"
#include "InstancedFlockingActor.generated.h"

class UInstancedStaticMeshComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class AInstancedFlockingActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* FlockMeshes;
    
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
    FFlockGenerationParameters FlockGenerationParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockMemberInitialConditions FlockInitialConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlockMemberInitialState> FlockInitialStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockingFadeParameters FadeParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlockFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnablePersonalities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockPersonalities Personalities;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFlockingParametersAdjustableBlend BlendFlockingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastFollowPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FlockFadeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector FlockFadeCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* FlockOriginalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* FlockFadeMaterial;
    
public:
    AInstancedFlockingActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartFade();
    
    UFUNCTION(BlueprintCallable)
    void SetFlockingStrength(float Strength);
    
    UFUNCTION(BlueprintCallable)
    void SetAdjustableParameters(FFlockingParametersAdjustable Parameters, float BlendTimeSeconds);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetAdjustableParameters(FFlockingParametersAdjustable& Parameters) const;
    
    UFUNCTION(BlueprintCallable)
    void Generate();
    
};

