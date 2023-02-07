#pragma once
#include "CoreMinimal.h"
#include "SceneActionConsoleVariable.h"
#include "SceneAction_ConsoleBase.h"
#include "SceneAction_ConsoleVariables.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleVariables : public USceneAction_ConsoleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionConsoleVariable> Variables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInShippingToo;
    
    USceneAction_ConsoleVariables();
};

