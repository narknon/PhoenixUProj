#pragma once
#include "CoreMinimal.h"
#include "ETimeOverrideType.h"
#include "TimeInput.h"
#include "TimeOverrideTimeOnly.h"
#include "TimeOverrideTimeInputRangeSceneRig.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTimeOverrideTimeInputRangeSceneRig : public UTimeOverrideTimeOnly {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput EndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeOverrideType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEndTime;
    
    UTimeOverrideTimeInputRangeSceneRig();
};

