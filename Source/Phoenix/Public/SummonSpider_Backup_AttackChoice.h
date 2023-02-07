#pragma once
#include "CoreMinimal.h"
#include "DW_RaiseDead_AttackChoice_GameChanger.h"
#include "SummonSpider_Backup_AttackChoice.generated.h"

class UEnemyAIAttackData;

UCLASS(Blueprintable, EditInlineNew)
class USummonSpider_Backup_AttackChoice : public UDW_RaiseDead_AttackChoice_GameChanger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyAIAttackData* DovSpawnAttackData;
    
    USummonSpider_Backup_AttackChoice();
};

