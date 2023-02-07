#pragma once
#include "CoreMinimal.h"
#include "SkyStateOverrides.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FSkyStateOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> SkyStateOverrides;
    
    FSkyStateOverrides();
};

