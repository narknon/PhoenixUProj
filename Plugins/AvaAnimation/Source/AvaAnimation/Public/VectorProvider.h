#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseProvider.h"
#include "VectorProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UVectorProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UVectorProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetVectorBP(const UObject* Context, float TimeOffset);
    
};

