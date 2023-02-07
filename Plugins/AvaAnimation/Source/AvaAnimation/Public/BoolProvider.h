#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "BoolProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBoolProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UBoolProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBoolBP(const UObject* Context);
    
};

