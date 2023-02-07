#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_BlackboardDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_BlackboardDirectionGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
    UTurnAdjust_BlackboardDirectionGetter();
};

