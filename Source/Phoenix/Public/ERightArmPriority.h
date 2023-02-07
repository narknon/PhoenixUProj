#pragma once
#include "CoreMinimal.h"
#include "ERightArmPriority.generated.h"

UENUM(BlueprintType)
namespace ERightArmPriority {
    enum Type {
        None,
        LowestPriority,
        UpperBodyIdle,
        UpperBodyAlert,
        UpperBodyAnticipation,
        ChannelSpell,
        UpperBodyFlourish,
        FullBodyUnderLumos,
        Lumos,
        FullBodyUsage,
        UpperBodyUsage,
        WandCastFail,
        FullBodyAbleAbility,
        UpperBodyAbleAbility,
        Cinematic,
        HighestPriority,
    };
}

