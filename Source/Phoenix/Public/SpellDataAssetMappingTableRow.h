#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SpellDataAssetMappingTableRow.generated.h"

class UEnemyAIAttackData;

USTRUCT(BlueprintType)
struct FSpellDataAssetMappingTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEnemyAIAttackData> SpellAttackDataAsset;
    
    PHOENIX_API FSpellDataAssetMappingTableRow();
};

