#pragma once
#include "CoreMinimal.h"
#include "ButtonWatcherRecord.h"
#include "TimedButtonWatcherRecord.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UTimedButtonWatcherRecord : public UButtonWatcherRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeTime;
    
    UTimedButtonWatcherRecord();
};

