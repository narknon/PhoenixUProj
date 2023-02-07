#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase_ComponentName.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigObjectActionBase_ComponentName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSceneRigObjectActionBase_ComponentName();
};

