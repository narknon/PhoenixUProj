#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "IntProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIntProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UIntProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetIntBP(const UObject* Context);
    
};

