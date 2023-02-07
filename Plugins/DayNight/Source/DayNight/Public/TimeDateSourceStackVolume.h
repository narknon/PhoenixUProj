#pragma once
#include "CoreMinimal.h"
#include "TimeDateSourceStackVolume.generated.h"

class UTimeSourceVolume;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeDateSourceStackVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeSourceVolume*> TimeSources;
    
    FTimeDateSourceStackVolume();
};

