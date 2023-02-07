#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BroomRiderActionBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderActionBase : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseBroomOnCompleteAction;
    
public:
    UBroomRiderActionBase();
};

