#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FXAdjustments.h"
#include "FXAdjustments_Offset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_Offset : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
public:
    UFXAdjustments_Offset();
};

