#pragma once
#include "CoreMinimal.h"
#include "StickWatcherRecord.h"
#include "SwapStickWatcherRecord.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API USwapStickWatcherRecord : public UStickWatcherRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SwapStickBaseName;
    
    USwapStickWatcherRecord();
};

