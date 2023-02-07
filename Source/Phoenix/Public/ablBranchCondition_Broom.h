#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EFlyingBroomState.h"
#include "ablBranchCondition_Broom.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablBranchCondition_Broom : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFlyingBroomState::Type> FlyingBroomCheckState;
    
public:
    UablBranchCondition_Broom();
};

