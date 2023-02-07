#pragma once
#include "CoreMinimal.h"
#include "CameraStackActorBehaviorTreePair.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;

USTRUCT(BlueprintType)
struct FCameraStackActorBehaviorTreePair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBehaviorTreeComponent* BTComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* BBComponent;
    
    CAMERASTACK_API FCameraStackActorBehaviorTreePair();
};

