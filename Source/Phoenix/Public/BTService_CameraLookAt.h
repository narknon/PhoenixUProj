#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_CameraBase.h"
#include "BTService_CameraLookAt.generated.h"

UCLASS(Blueprintable)
class UBTService_CameraLookAt : public UBTService_CameraBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector LookAtStrengthKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector UserInputActiveKey;
    
public:
    UBTService_CameraLookAt();
};

