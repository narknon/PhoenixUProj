#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleCommandBase.h"
#include "SceneAction_ConsoleCommandInShippingToo.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleCommandInShippingToo : public USceneAction_ConsoleCommandBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInShippingToo;
    
    USceneAction_ConsoleCommandInShippingToo();
};

