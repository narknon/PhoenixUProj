#pragma once
#include "CoreMinimal.h"
#include "TimeSourceSlotSetupName.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeSourceSlotSetupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FTimeSourceSlotSetupName();
};

