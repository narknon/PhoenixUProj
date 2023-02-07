#pragma once
#include "CoreMinimal.h"
#include "AdaptationOverrideInterfaces.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAdaptationOverrideInterfaces {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> PriorityAdaptationOverrides;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> StackedAdaptationOverrides;
    
    RENDERSETTINGS_API FAdaptationOverrideInterfaces();
};

