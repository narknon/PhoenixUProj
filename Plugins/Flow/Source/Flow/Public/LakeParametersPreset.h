#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LakeParametersPreset.generated.h"

class ULakeParameterGenerator;

UCLASS(Blueprintable)
class ULakeParametersPreset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    ULakeParameterGenerator* ParametersGenerator;
    
    ULakeParametersPreset();
};

