#pragma once
#include "CoreMinimal.h"
#include "LakeParameterGeneratorBase.h"
#include "LakeParameterPresetGenerator.generated.h"

class ULakeParametersPreset;

UCLASS(Blueprintable, EditInlineNew)
class FLOW_API ULakeParameterPresetGenerator : public ULakeParameterGeneratorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULakeParametersPreset* Preset;
    
    ULakeParameterPresetGenerator();
};

