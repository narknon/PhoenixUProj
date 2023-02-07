#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "EMultiFXBeamSource.h"
#include "EMultiFXLocation.h"
#include "FXAdjustments_Beam.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_Beam : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXBeamSource SourceObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXLocation SourceLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXLocation TargetLocation;
    
public:
    UFXAdjustments_Beam();
};

