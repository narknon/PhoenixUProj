#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModThreshold.h"
#include "LightSettingsModThresholdConsoleVariableBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModThresholdConsoleVariableBase : public ULightSettingsModThreshold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConsoleVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsoleVariableDefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreateConsoleVariableIfMissing;
    
    ULightSettingsModThresholdConsoleVariableBase();
};

