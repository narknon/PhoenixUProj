#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_BeamTargetAttach.h"
#include "FXUpdate_BeamTargetLocation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_BeamTargetLocation : public UFXUpdate_BeamTargetAttach {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PropertyName;
    
public:
    UFXUpdate_BeamTargetLocation();
};

