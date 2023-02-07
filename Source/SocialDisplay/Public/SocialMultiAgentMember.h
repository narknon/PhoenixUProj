#pragma once
#include "CoreMinimal.h"
#include "SocialAgent.h"
#include "SocialMultiAgentMember.generated.h"

USTRUCT(BlueprintType)
struct SOCIALDISPLAY_API FSocialMultiAgentMember : public FSocialAgent {
    GENERATED_BODY()
public:
    FSocialMultiAgentMember();
};

