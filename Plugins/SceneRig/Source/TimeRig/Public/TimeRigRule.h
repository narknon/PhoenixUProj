#pragma once
#include "CoreMinimal.h"
#include "TimeRigGenerator.h"
#include "TimeRigInterval.h"
#include "TimeRigRule.generated.h"

class UTimeRigElement;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigRule : public UTimeRigInterval, public ITimeRigGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> BakedChildren;
    
    UTimeRigRule();
    
    // Fix for true pure virtual functions not being implemented
};

