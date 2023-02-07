#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseProvider.h"
#include "BlendSpaceInputProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UBlendSpaceInputProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UBlendSpaceInputProvider();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool GetBlendSpaceInput(UObject* Caller, FVector& BlendSpaceInput) const;
    
};

