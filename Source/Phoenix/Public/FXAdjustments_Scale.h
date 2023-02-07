#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FXAdjustments.h"
#include "FXAdjustments_Scale.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_Scale : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
public:
    UFXAdjustments_Scale();
};

