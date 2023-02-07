#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "BroomRiderAction_WaitForHermesMessage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_WaitForHermesMessage : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MessageName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseWhileWaiting;
    
public:
    UBroomRiderAction_WaitForHermesMessage();
};

