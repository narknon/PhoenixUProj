#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlendDomain.h"
#include "WorldBaseHeightInterface.h"
#include "WorldBaseHeightBase.generated.h"

UCLASS(Abstract, Blueprintable)
class GLOBALLIGHTRIG_API AWorldBaseHeightBase : public AActor, public IWorldBaseHeightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Affects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    AWorldBaseHeightBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

