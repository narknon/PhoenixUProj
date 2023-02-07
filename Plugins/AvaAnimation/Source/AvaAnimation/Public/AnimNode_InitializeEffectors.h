#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "InitializeEffectorData.h"
#include "AnimNode_InitializeEffectors.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_InitializeEffectors : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInitializeEffectorData> EffectorData;
    
    FAnimNode_InitializeEffectors();
};

