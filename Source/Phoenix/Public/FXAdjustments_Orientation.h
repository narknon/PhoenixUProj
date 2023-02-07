#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "EMultiFXOrientation.h"
#include "FXAdjustments_Orientation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_Orientation : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXOrientation Orientation;
    
public:
    UFXAdjustments_Orientation();
};

