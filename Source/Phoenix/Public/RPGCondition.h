#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPGCondition.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGCondition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConditionMetWhenTrue;
    
    URPGCondition();
};

