#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AvaMotionWarpingModifier.h"
#include "AvaMotionWarpingModifier_Scale.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaMotionWarpingModifier_Scale : public FAvaMotionWarpingModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    FAvaMotionWarpingModifier_Scale();
};

