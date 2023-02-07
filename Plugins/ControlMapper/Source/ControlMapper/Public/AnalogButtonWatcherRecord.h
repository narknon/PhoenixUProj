#pragma once
#include "CoreMinimal.h"
#include "ButtonWatcherRecord.h"
#include "AnalogButtonWatcherRecord.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UAnalogButtonWatcherRecord : public UButtonWatcherRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PressedValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReleasedValue;
    
    UAnalogButtonWatcherRecord();
};

