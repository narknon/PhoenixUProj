#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_ToBlackboardLocationGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_ToBlackboardLocationGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
public:
    UTurnAdjust_ToBlackboardLocationGetter();
};

