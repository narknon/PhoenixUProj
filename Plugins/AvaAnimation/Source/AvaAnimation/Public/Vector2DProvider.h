#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseProvider.h"
#include "Vector2DProvider.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UVector2DProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UVector2DProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetVector2DBP(const UObject* Context);
    
};

