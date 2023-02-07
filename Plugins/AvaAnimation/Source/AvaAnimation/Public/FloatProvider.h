#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "FloatProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFloatProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UFloatProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFloatBP(const UObject* Context, float TimeOffset);
    
};

