#pragma once
#include "CoreMinimal.h"
#include "EPartialBodyState.generated.h"

UENUM(BlueprintType)
namespace EPartialBodyState {
    enum Type {
        None,
        Protego,
        SpellCombo,
        WandEquip,
        SpellFinisher,
        Carry,
        PickupSighted,
        PickupCollect,
        LootCollect,
        StationInteract,
        AttackAnticipation,
        UseInventoryItem,
        WandEquipped,
        BlockedByWall,
        ChannelSpell,
        Cinematic,
        Lumos,
        WandUnEquip,
        Waving,
    };
}

