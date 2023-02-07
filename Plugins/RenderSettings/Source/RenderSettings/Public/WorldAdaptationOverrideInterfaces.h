#pragma once
#include "CoreMinimal.h"
#include "AdaptationOverrideInterfaces.h"
#include "WorldAdaptationOverrideInterfaces.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FWorldAdaptationOverrideInterfaces {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FAdaptationOverrideInterfaces> WorldMap;
    
    RENDERSETTINGS_API FWorldAdaptationOverrideInterfaces();
};

