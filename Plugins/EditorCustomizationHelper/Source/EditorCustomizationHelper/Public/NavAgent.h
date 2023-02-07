#pragma once
#include "CoreMinimal.h"
#include "NavAgent.generated.h"

USTRUCT(BlueprintType)
struct EDITORCUSTOMIZATIONHELPER_API FNavAgent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName AgentName;
    
    FNavAgent();
};

