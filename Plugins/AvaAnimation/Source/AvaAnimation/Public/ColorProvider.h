#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseProvider.h"
#include "ColorProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UColorProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UColorProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetColorBP(const UObject* Context, float TimeOffset);
    
};

