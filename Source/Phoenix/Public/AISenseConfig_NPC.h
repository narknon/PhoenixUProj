#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseConfig.h"
#include "AISenseConfig_NPC.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAISenseConfig_NPC : public UAISenseConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvaluateRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartActive;
    
    UAISenseConfig_NPC();
};

