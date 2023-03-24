#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VegetationInteractionArbitror.generated.h"

class UMaterialParameterCollection;
class UVegetationInteractionComponent;

UCLASS(Blueprintable, Transient)
class AVegetationInteractionArbitror : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplacementCameraDistanceCutoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuspend;
    
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<UVegetationInteractionComponent>> VICs;
    
public:
    AVegetationInteractionArbitror(const FObjectInitializer& ObjectInitializer);
};

