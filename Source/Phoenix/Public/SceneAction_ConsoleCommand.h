#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleCommandBase.h"
#include "SceneAction_ConsoleCommand.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleCommand : public USceneAction_ConsoleCommandBase {
    GENERATED_BODY()
public:
    USceneAction_ConsoleCommand();
};

