#pragma once
#include "CoreMinimal.h"
#include "SceneRig.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_Transform.h"
#include "SceneRig_Intrusion.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API USceneRig_Intrusion : public USceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Enforcer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform RootLocation;
    
    USceneRig_Intrusion();
};

