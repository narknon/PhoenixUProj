#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_BroomFlight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_BroomFlight : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpolationWeight;
    
public:
    UFXUpdate_BroomFlight();
};

