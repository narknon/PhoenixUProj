#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_ObjectFade.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ObjectFade : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bStartedFade;
    
    USceneActionState_ObjectFade();
};

