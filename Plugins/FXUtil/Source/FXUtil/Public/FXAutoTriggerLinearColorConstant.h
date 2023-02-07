#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FXAutoTriggerLinearColor.h"
#include "FXAutoTriggerLinearColorConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerLinearColorConstant : public UFXAutoTriggerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UFXAutoTriggerLinearColorConstant();
};

