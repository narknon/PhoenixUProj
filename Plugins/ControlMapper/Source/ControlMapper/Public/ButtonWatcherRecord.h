#pragma once
#include "CoreMinimal.h"
#include "WatcherRecord.h"
#include "ButtonWatcherRecord.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UButtonWatcherRecord : public UWatcherRecord {
    GENERATED_BODY()
public:
    UButtonWatcherRecord();
};

