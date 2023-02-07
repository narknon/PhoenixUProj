#pragma once
#include "CoreMinimal.h"
#include "UberExposureDriver.h"
#include "UberExposureDriverBlueprintBase.generated.h"

class AActor;
class UWorld;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriverBlueprintBase : public UUberExposureDriver {
    GENERATED_BODY()
public:
    UUberExposureDriverBlueprintBase();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float UberExposureDriverGetValue(UWorld* World, AActor* Owner) const;
    
};

