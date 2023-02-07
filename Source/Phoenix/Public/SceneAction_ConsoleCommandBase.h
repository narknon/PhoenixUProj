#pragma once
#include "CoreMinimal.h"
#include "SceneActionConsoleCommand.h"
#include "SceneAction_ConsoleBase.h"
#include "SceneAction_ConsoleCommandBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleCommandBase : public USceneAction_ConsoleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionConsoleCommand> Commands;
    
    USceneAction_ConsoleCommandBase();
};

