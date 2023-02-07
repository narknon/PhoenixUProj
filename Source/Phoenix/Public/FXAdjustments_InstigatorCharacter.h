#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "FXAdjustments_InstigatorCharacter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_InstigatorCharacter : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailIfNotFound;
    
public:
    UFXAdjustments_InstigatorCharacter();
};

