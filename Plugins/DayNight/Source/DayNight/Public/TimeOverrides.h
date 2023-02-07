#pragma once
#include "CoreMinimal.h"
#include "TimeOverrides.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> TimeOverrides;
    
    FTimeOverrides();
};

