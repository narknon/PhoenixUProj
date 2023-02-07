#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeLerp.h"
#include "TimeController.generated.h"

class UTimeSource;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeSource* TimeDateSource;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime FilteredTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimeLerp TimeTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RateTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RateFilter;
    
public:
    FTimeController();
};

