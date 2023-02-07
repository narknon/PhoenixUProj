#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "EBarrelRollDirection.h"
#include "BroomRiderAction_BarrelRoll.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_BarrelRoll : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EBarrelRollDirection RollDirection;
    
public:
    UBroomRiderAction_BarrelRoll();
};

