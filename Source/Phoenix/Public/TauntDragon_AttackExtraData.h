#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackExtraData.h"
#include "TauntDragon_AttackExtraData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTauntDragon_AttackExtraData : public UEnemy_AttackExtraData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TargetObjectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedAttackScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceThisAttack;
    
    UTauntDragon_AttackExtraData();
};

