#pragma once
#include "CoreMinimal.h"
#include "WatcherRecord.h"
#include "StickWatcherRecord.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class CONTROLMAPPER_API UStickWatcherRecord : public UWatcherRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* StickMagCurve;
    
    UStickWatcherRecord();
};

