#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseProvider.h"
#include "TransformProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UTransformProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UTransformProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetTransformBP(const UObject* Context, float TimeOffset) const;
    
};

