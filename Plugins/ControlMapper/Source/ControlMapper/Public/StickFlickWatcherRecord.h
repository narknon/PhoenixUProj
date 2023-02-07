#pragma once
#include "CoreMinimal.h"
#include "StickWatcherRecord.h"
#include "StickFlickWatcherRecord.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UStickFlickWatcherRecord : public UStickWatcherRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreFlickRestTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMagnitude;
    
    UStickFlickWatcherRecord();
};

