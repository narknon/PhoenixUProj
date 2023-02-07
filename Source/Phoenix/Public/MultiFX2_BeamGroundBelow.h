#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_BeamTargetBase.h"
#include "MultiFX2_BeamGroundBelow.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_BeamGroundBelow : public UMultiFX2_BeamTargetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayIfNoGround;
    
    UMultiFX2_BeamGroundBelow();
};

