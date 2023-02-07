#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PT_Progression.generated.h"

class UDataTable;
class UPT_Tree;

UCLASS(Blueprintable)
class UPT_Progression : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPT_Tree* m_tree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* m_baseValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* m_upgrades;
    
    UPT_Progression();
};

