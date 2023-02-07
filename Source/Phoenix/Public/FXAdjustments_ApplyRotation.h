#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FXAdjustments.h"
#include "FXAdjustments_ApplyRotation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_ApplyRotation : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotation;
    
public:
    UFXAdjustments_ApplyRotation();
};

