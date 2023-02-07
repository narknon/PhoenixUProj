#pragma once
#include "CoreMinimal.h"
#include "EAttackState.generated.h"

UENUM(BlueprintType)
namespace EAttackState {
    enum Type {
        None,
        AttackCombo1,
        AttackCombo2,
        AttackCombo3,
        AttackCombo4,
        AttackCombo5,
        AttackFinisher1,
        AttackFinisher2,
        AttackFinisher3,
        AttackAOESpell,
        AttackAOEArrestoMomentum,
        AttackAOEDepulso,
        AttackAOEExpectoPatronum,
        AttackAOEExpulso,
        AttackAOEIncendio,
        AttackAOELevioso,
        AttackAOELumos,
        AttackAOEReparo,
    };
}

