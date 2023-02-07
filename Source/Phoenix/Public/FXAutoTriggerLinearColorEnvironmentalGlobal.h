#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsVectorOrColorName.h"
#include "FXAutoTriggerLinearColor.h"
#include "FXAutoTriggerLinearColorEnvironmentalGlobal.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerLinearColorEnvironmentalGlobal : public UFXAutoTriggerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsVectorOrColorName EnvironmentalGlobal;
    
    UFXAutoTriggerLinearColorEnvironmentalGlobal();
};

