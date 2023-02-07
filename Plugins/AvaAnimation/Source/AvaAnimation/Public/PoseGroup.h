#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationExplicitPoseGroupReference.h"
#include "PoseGroupTransition.h"
#include "PoseGroup.generated.h"

class UBaseArchitectAsset;

UCLASS(Blueprintable)
class AVAANIMATION_API UPoseGroup : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBaseArchitectAsset* LookUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPoseGroupTransition> TransitionsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationExplicitPoseGroupReference ExplicitPoseGroupName;
    
    UPoseGroup();
};

