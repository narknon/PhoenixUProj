#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AblAbilityTask.h"
#include "AblSetCollisionChannelTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetCollisionChannelTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> m_Channel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RestoreOnEnd;
    
public:
    UAblSetCollisionChannelTask();
};

