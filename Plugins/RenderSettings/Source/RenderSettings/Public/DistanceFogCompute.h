#pragma once
#include "CoreMinimal.h"
#include "DistanceFogCompute.generated.h"

class UMaterialInterface;
class UPostProcessComponent;

USTRUCT(BlueprintType)
struct FDistanceFogCompute {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* FogPostProcess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ActivePPMaterial;
    
public:
    RENDERSETTINGS_API FDistanceFogCompute();
};

