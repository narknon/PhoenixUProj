#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolSeason.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolSeason : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seasons;
    
    UFXAutoTriggerBoolSeason();
};

