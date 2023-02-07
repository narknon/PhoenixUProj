#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "BroomRiderAction_WaitForPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_WaitForPlayer : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
public:
    UBroomRiderAction_WaitForPlayer();
};

