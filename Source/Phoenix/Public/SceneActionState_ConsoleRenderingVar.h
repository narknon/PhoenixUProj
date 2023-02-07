#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableFlexValue.h"
#include "SceneRigActionState.h"
#include "SceneActionState_ConsoleRenderingVar.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ConsoleRenderingVar : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FConsoleVariableFlexValue Value;
    
    USceneActionState_ConsoleRenderingVar();
};

