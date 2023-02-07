#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableLienEntry.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_ConsoleRenderingVarSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleRenderingVarSimple : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleVariableLienEntry Console;
    
    USceneAction_ConsoleRenderingVarSimple();
};

