#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "BroomRiderAction_SendHermesMessage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_SendHermesMessage : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MessageName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOwned;
    
public:
    UBroomRiderAction_SendHermesMessage();
};

