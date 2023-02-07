#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PT_Tree.generated.h"

class UPT_Tree;

UCLASS(Blueprintable)
class UPT_Tree : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_upgradeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPT_Tree*> m_children;
    
    UPT_Tree();
};

