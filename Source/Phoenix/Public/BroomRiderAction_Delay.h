#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "BroomRiderAction_Delay.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_Delay : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delay;
    
public:
    UBroomRiderAction_Delay();
};

