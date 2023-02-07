#pragma once
#include "CoreMinimal.h"
#include "ETimeOverrideType.h"
#include "TimeInput.h"
#include "TimeOverrideTimeOnly.h"
#include "TimeOverrideTimeInput.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideTimeInput : public UTimeOverrideTimeOnly {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeOverrideType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeOverrideTimeInput();
};

