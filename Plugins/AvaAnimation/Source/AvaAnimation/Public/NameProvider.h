#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "NameProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UNameProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UNameProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNameBP(const UObject* Caller) const;
    
};

