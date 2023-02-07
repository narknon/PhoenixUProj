#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_ConsoleVariables.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ConsoleVariables : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSetValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bRestoredValues;
    
    USceneActionState_ConsoleVariables();
};

